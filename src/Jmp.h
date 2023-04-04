#ifndef __JMP__
#define __JMP__
#include "instruction.h"
class Jmp : public Instruction {
    int getArgCount() {
        return 1;
    }
    string getName() {
        return "jmp";
    }
};
#endif