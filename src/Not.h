#ifndef __NOT__
#define __NOT__
#include "instruction.h"
class Not : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "not";
    }
};
#endif