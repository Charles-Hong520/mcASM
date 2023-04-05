#ifndef __OPERATION__
#define __OPERATION__
#include "../instruction.h"
class Operation : public Instruction {
    int getArgCount() {
        return 3;
    }
    virtual string getName() {
        return "op";
    }
};
#endif