#ifndef __NE__
#define __NE__
#include "instruction.h"
class Ne : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "ne";
    }
};
#endif