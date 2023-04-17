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

        
        ans += "function ";
        ans += PKGNM;
        ans += ":" + this->name+"\n";
        ans += "scoreboard players operation "+args[1]+" "+OBJ_VARS+" = "+RET+" "+OBJ_INTERNAL;
        return ans;
    }
};
#endif