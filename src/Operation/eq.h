#ifndef __EQ__
#define __EQ__
#include "operation.h"

class Eq : public Operation {
    string getName() {
        return "eq";
    }
};
#endif