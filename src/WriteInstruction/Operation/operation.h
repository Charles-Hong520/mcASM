#ifndef __OPERATION__
#define __OPERATION__
#include "../writeinstruction.h"
class Operation : public WriteInstruction {
    int getArgCount() {
        return 3;
    }
    virtual string getName() {
        return "op";
    }
};
#endif