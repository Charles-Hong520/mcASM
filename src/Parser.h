#ifndef __PARSER__
#define __PARSER__
#include "all_headers.h"
#include <sys/stat.h>
#include <sys/types.h>
class Parser {
    #define currArgs lines[lineNumber] 
    #define currName currArgs[0]
    #define currInst mp[currName]
    #define currLab lab[currName]

    //stores all info
    vector<vector<string>> lines;
    map<string, vector<int>> lab;
    map<string, Instruction*> mp;
    vector<Error> errs;
    set<string> RAWvars;
    int lineNumber = 0;

    public:
    Parser() {
        mp = {
            {"add", new Add()},
            {"sub", new Sub()},
            {"ass", new Ass()},
            {"and", new And()},
            {"mul", new Mul()},
            {"div", new Div()},
            {"mod", new Mod()},
            {"or", new Or()},
            {"not", new Not()},
            {"bitand", new Bitand()},
            {"bitor", new Bitor()},
            {"bitnot", new Bitnot()},
            {"lt", new Lt()},
            {"eq", new Eq()},
            {"gt", new Gt()},
            {"le", new Le()},
            {"ge", new Ge()},
            {"ne", new Ne()},
            {"jmp", new Jmp()},
            {"jif", new Jif()}
        };
    }
    bool parse(std::ifstream & fin) {
        string line;
        while(getline(fin, line)) {
            parseLine(line);
        }


        for(lineNumber = 0; lineNumber < (int) lines.size(); lineNumber++) {      
            if(currArgs.empty()) continue;
            if(isLabel()) {
                insertLabel(lineNumber);
            } else if(hasLabelSuffix(currName)) {
                errs.push_back({{lineNumber}, currName, "Label Has Parameters"});
            }
        }

        for(auto [l,v] : lab) {
            if(v.size()>1) errs.push_back({v, l, "Duplicate Label"});
        }
        for(lineNumber = 0; lineNumber < (int) lines.size(); lineNumber++) {
            if(currArgs.empty()) continue;
            if(hasLabelSuffix(currName)) continue;
            if(!hasValidInstructionName()) {
                errs.push_back({{lineNumber}, currName, "Unknown Instruction"});
            } else {
                if(!hasValidParamCount()) {
                    errs.push_back({{lineNumber,currInst->getArgCount(),(int)currArgs.size()-1},currName,"Parameter Count"});
                }

                for(int j = 2; j < (int) currArgs.size(); j++) {
                    if(isVariable(currArgs[j]) && currInst->getReq(j-1)!='l') {
                        if(RAWvars.count(currArgs[j])==0) {
                            //read before written to
                            errs.push_back({{lineNumber}, currArgs[j], "uninitialized variable"});
                        }
                    }
                }
                if(currArgs.size()>=2) {
                    if(isVariable(currArgs[1])) {
                        RAWvars.insert(currArgs[1]);
                    }
                }
                //check for correct type in each slot
                //v is variable only
                //n is v || number
                //l is label only
                char reqType;
                for(int j = 1; j < (int) currArgs.size(); j++) {

                    reqType = currInst->getReq(j-1);

                    if(reqType=='v') {
                        if(!isVariable(currArgs[j])) {
                            errs.push_back({{lineNumber,j}, currArgs[j], "variable only"});
                        }
                    } else if(reqType=='n') {
                        if(!isNumber(currArgs[j]) && !isVariable(currArgs[j])) {
                            errs.push_back({{lineNumber,j}, currArgs[j], "var or num only"});                        
                        }

                    } else if(reqType=='l') {
                        if(lab.count(currArgs[j])==0) {
                            errs.push_back({{lineNumber,j}, currArgs[j], "labels only"});
                        } 
                    } else {
                        // cout<<"something wrong in arg check charles"<<endl;
                        // cout<<lineNumber<<" "<<j<<" "<<reqType<<endl;
                    }
                }
            }
        }
        if(!errs.empty()) return false;
        //clean the input file to get rid of whitespace and assign numbers to labels
        
        int actualSize = 0;
        vector<vector<string>> tmp;
        for(lineNumber = 0; lineNumber < (int) lines.size(); lineNumber++) {
            if(currArgs.empty()) continue;
            tmp.push_back(currArgs);

        }


        lines = tmp;
        tmp.resize(0);

        for(lineNumber = 0; lineNumber < (int) lines.size(); lineNumber++) {
            
            if(isLabel()) {
                if(lineNumber-1 >= 0) {
                    lineNumber--;
                    //if previous line is label
                    if(isLabel()) {
                        string tmpName = lines[lineNumber+1][0];
                        tmpName.pop_back();
                        string prevName = currName;
                        prevName.pop_back();
                        lab[tmpName][0]=lab[prevName][0];
                    } else { //curr line is the first label
                        lineNumber++;
                        string tmpName = currName;
                        tmpName.pop_back();
                        lab[tmpName][0]=actualSize;
                        lineNumber--;
                    }
                    lineNumber++;
                } else {
                    string tmpName = currName;
                    tmpName.pop_back();
                    lab[tmpName][0]=actualSize;
                }
            } else {
                tmp.push_back(currArgs);
                actualSize++;
            }
        }
        lines = tmp;
        tmp.clear();



        for(lineNumber = 0; lineNumber < (int) lines.size(); lineNumber++) {
            for(int i = 1; i < (int) currArgs.size(); i++) {
                if(currInst->getReq(i-1)=='l') {
                    currArgs[i] = to_string(lab[currArgs[i]][0]+1);
                }
            }
        }
        std::ofstream fout("Output/IR.mc");
        for(vector<string> & vs : lines) {
            for(string & s : vs) {
                fout<<s<<" ";
            }
            fout<<endl;
        }
        fout.close();
        return true;
    }
    void printErrors() {
        for(auto er : errs) {
            cout<<er.message()<<endl;
        }
    }
    void generateMcfunctionFiles() {
        mkdir("../Output", 0777);
        for(lineNumber = 0; lineNumber < (int)lines.size(); lineNumber++) {
            cout<<lineNumber+1<<"\n"<<currInst->generate(currArgs);
        }
    }
    private:
    
    //breaks the line to pieces and assigns them to "variables for 1 instance"
    void parseLine(const string& line) {
        vector<string> args;
        stringstream ss(line);
        string word;
        while(ss>>word) args.push_back(word);
        if(!args.empty()) for(char & c : args[0]) c |= 32; //32 is bitmask for toLowerCase
        lines.push_back(args);
    }
    bool hasValidInstructionName() {
        return mp.count(currName); 
    }
    bool isLabel() {
        return currArgs.size()==1 && hasLabelSuffix(currName);
    }
    bool hasValidParamCount() {
        return currInst->getArgCount()+1 == (int) currArgs.size();
    }
    void insertLabel(int linenum) {
        string tmpName = currName;
        tmpName.pop_back();
        lab[tmpName].push_back(linenum);
    }
    bool hasLabelSuffix(const string& str) {
        return str.back()==':';
    }
};

#endif