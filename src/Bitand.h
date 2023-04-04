#ifndef __BITAND__
#define __BITAND__
#include "instruction.h"
class Bitand : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif