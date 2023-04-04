#ifndef __BITOR__
#define __BITOR__
#include "instruction.h"
class Bitor : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "bitor";
    }
};
#endif