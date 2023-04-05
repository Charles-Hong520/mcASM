#ifndef __BITNOT__
#define __BITNOT__
#include "writeinstruction.h"
class Bitnot : public WriteInstruction {
    int getArgCount() {
        return 2;
    }
    string getName() {
        return "bitnot";
    }
};
#endif