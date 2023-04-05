#ifndef __ASS__
#define __ASS__
#include "writeinstruction.h"
class Ass : public WriteInstruction {
    int getArgCount() {
        return 2;
    }
    string getName() {
        return "ass";
    }
};
#endif