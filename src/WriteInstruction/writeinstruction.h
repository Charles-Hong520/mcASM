#ifndef __WRITEINSTRUCTION__
#define __WRITEINSTRUCTION__
#include "../instruction.h"
class WriteInstruction : public Instruction {
    int getArgCount() {
        return 2;
    }
    virtual string getName() {
        return "writeinstruction";
    }
};
#endif