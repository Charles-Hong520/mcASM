#ifndef __AND__
#define __AND__
#include "instruction.h"
class And : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif