#ifndef __JIF__
#define __JIF__
#include "../instruction.h"
class Jif : public Instruction {
    public:
    Jif() {
        name = "jif";
        argCount = 2;
        reqs = {'v', 'l'};
    }
};
#endif