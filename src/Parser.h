#ifndef __PARSER__
#define __PARSER__
#include "all_headers.h"
class Parser {
    map<string, Instruction*> mp;
    vector<string> args;
    string currname;
    public:
    Instruction* mcinst; 
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
    string getInstName() {return currname;}
    int getArgCount() {return mp[currname]->getArgCount();}
    void parse(const string& line) {
        args.resize(0);
        stringstream ss(line);
        string word;
        ss>>currname;
        while(ss>>word) args.push_back(word); 
        for(char & c : currname) c |= 32; //32 is bitmask for toLowerCase        
        //point to correct Instruction()
        //mcinst = mp[currname];
    }
    bool hasValidName() {
        return mp.count(currname); 
    }
    bool hasValidParamCount() {
        return mp[currname]->getArgCount() == args.size();
    }
    
};

#endif