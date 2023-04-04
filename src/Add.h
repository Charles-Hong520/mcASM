#ifndef __ADD__
#define __ADD__
#include "instruction.h"
class Add : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "add";
    }
};
#endif