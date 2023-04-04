#ifndef __BITNOT__
#define __BITNOT__
#include "instruction.h"
class Bitnot : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "bitnot";
    }
};
#endif