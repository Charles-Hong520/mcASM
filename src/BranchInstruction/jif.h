#ifndef __JIF__
#define __JIF__
#include "../instruction.h"
class Jif : public Instruction {
    int getArgCount() {
        return 2;
    }
    string getName() {
        return "jif";
    }
};
#endif