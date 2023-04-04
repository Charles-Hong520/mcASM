#ifndef __LT__
#define __LT__
#include "instruction.h"
class Lt : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "";
    }
};
#endif