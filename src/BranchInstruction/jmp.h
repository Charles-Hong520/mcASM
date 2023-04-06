#ifndef __JMP__
#define __JMP__
#include "../instruction.h"
class Jmp : public Instruction {
    public:
    Jmp() { 
        name = "jmp";
        argCount = 1;
        reqs = {'l'};
    }
};
#endif