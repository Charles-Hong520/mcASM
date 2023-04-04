#ifndef __EQ__
#define __EQ__
#include "instruction.h"
class Eq : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "eq";
    }
};
#endif