#ifndef __SUB__
#define __SUB__
#include "instruction.h"
class Sub : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "sub";
    }
};
#endif