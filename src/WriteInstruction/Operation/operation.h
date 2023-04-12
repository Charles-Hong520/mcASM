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
        return "";
    }
};
#endif