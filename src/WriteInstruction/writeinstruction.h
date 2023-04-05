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
};
#endif