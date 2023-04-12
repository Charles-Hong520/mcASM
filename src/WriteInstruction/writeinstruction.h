#ifndef __WRITEINSTRUCTION__
#define __WRITEINSTRUCTION__
#include "../instruction.h"
class WriteInstruction : public Instruction {
    public:
    WriteInstruction() {
        name = "writeinstruction";
        argCount = 2;
        reqs = {'v','n'};
    }
    string generate(const vector<string>& args) {
        string ans = "";
        
        if(isNumber(args[2])) ans += mcAssignImm(ARG1,args[2].substr(1,args[2].size()-1));
        else ans += mcAssignVar(ARG1,args[2]);

        
        ans += "run "+this->name+".mc\n";
        ans += mcAssignVar(args[1], RET);
        return ans;
    }
};
#endif