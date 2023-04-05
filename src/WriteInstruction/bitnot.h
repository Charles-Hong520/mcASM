#ifndef __BITNOT__
#define __BITNOT__
#include "writeinstruction.h"
class Bitnot : public WriteInstruction {
    public:
    Bitnot() {
        name = "bitnot";
    }
};
#endif