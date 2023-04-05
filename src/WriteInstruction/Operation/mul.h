#ifndef __MUL__
#define __MUL__
#include "operation.h"
class Mul : public Operation {
    string getName() {
        return "mul";
    }
};
#endif