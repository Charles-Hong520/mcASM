#ifndef __AND__
#define __AND__
#include "instruction.h"
class And : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "and";
    }
};
#endif