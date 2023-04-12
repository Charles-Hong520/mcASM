#ifndef __OPERATION__
#define __OPERATION__
#include "../writeinstruction.h"
class Operation : public WriteInstruction {
    public:
    Operation() {
        name = "op";
        argCount = 3;
        reqs = {'v', 'n', 'n'};
    }
    string generate(const vector<string>& args) {
        string ans = "";
        
        if(isNumber(args[2])) ans += mcAssignImm(ARG1,args[2].substr(1,args[2].size()-1));
        else ans += mcAssignVar(ARG1,args[2]);
        
        if(isNumber(args[3])) ans += mcAssignImm(ARG2,args[3].substr(1,args[3].size()-1));
        else ans += mcAssignVar(ARG2,args[3]);
        
        ans += "run "+this->name+".mc\n";
        ans += mcAssignVar(args[1], RET);
        return ans;
    }
};
#endif