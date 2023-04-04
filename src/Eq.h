#ifndef __EQ__
#define __EQ__
#include "instruction.h"
class Eq : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif