#ifndef __GT__
#define __GT__
#include "instruction.h"
class Gt : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "gt";
    }
};
#endif