#ifndef __AND__
#define __AND__
#include "operation.h"
class And : public Operation {
    string getName() {
        return "and";
    }
};
#endif