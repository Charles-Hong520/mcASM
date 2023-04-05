#ifndef __NOT__
#define __NOT__
#include "writeinstruction.h"
class Not : public WriteInstruction {
    public:
    Not() {
        name = "not";
    }
};
#endif