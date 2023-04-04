#ifndef __ADD__
#define __ADD__
#include "instruction.h"
class Add : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif