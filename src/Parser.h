#ifndef __PARSER__
#define __PARSER__
#include "all_headers.h"
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
    int lineNumber = 0;
    //variables for 1 instance of instruction
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
    void parse(std::ifstream & fin) {
        string line;
        while(getline(fin, line)) {
            parseLine(line);
        }


        for(lineNumber = 0; lineNumber < lines.size(); lineNumber++) {      
            if(isLabel()) {
                insertLabel(lineNumber);
            } else if(hasLabelSuffix(currName)) {
                errs.push_back({{lineNumber}, currName, "Label Has Parameters"});
            }
        }

        for(auto [l,v] : lab) {
            if(v.size()>1) errs.push_back({v, l, "Duplicate Label"});
        }
        for(lineNumber = 0; lineNumber < lines.size(); lineNumber++) {
            if(!hasValidInstructionName()) {
                errs.push_back({{lineNumber}, currName, "Unknown Instruction"});
            } else {
                if(!hasValidParamCount()) {
                    errs.push_back({{lineNumber,currInst->getArgCount(),(int)currArgs.size()-1},currName,"Parameter Count"});
                }
                //check for correct type in each slot
                //v is variable only
                //n is v || number
                //l is label only
                char reqType;
                for(int j = 1; j < currArgs.size(); j++) {
                    reqType = currInst->getReq(j-1);
                    if(reqType=='v') {
                        if(!isVariable(currArgs[j])) {
                            errs.push_back({{lineNumber}, currArgs[j], "variable only"});
                        }
                    } else if(reqType=='n') {
                        if(!isNumber(currArgs[j]) && !isVariable(currArgs[j])) {
                            errs.push_back({{lineNumber}, currArgs[j], "var or num only"});                        
                        }

                    } else if(reqType=='l') {
                        if(lab.count(currArgs[j])==0) {
                            errs.push_back({{lineNumber}, currArgs[j], "labels only"});
                        } 
                    } else {
                        cout<<"something wrong in arg check charles"<<endl;
                    }
                }
            }
        }
    }
    private:

    //breaks the line to pieces and assigns them to "variables for 1 instance"
    void parseLine(const string& line) {
        if(line=="") {
            lines.push_back({});
            return;
        }

        vector<string> args;
        stringstream ss(line);
        string word;
        while(ss>>word) args.push_back(word); 
        for(char & c : args[0]) c |= 32; //32 is bitmask for toLowerCase

        lines.push_back(args);
    }
    bool hasValidInstructionName() {
        return mp.count(currName); 
    }
    bool isLabel() {
        return currArgs.size()==1 && hasLabelSuffix(currName);
    }
    bool hasValidParamCount() {
        return currInst->getArgCount()+1 == currArgs.size();
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