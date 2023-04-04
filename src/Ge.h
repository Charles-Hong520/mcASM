#ifndef __GE__
#define __GE__
#include "instruction.h"
class Ge : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif