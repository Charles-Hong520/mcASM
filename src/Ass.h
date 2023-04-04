#ifndef __ASS__
#define __ASS__
#include "instruction.h"
class Ass : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "";
    }
};
#endif