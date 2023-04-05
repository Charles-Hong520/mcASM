#ifndef __NOT__
#define __NOT__
#include "writeinstruction.h"
class Not : public WriteInstruction {
    int getArgCount() {
        return 2;
    }
    string getName() {
        return "not";
    }
};
#endif