#ifndef __OR__
#define __OR__
#include "instruction.h"
class Or : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "or";
    }
};
#endif