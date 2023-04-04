#ifndef __GE__
#define __GE__
#include "instruction.h"
class Ge : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "ge";
    }
};
#endif