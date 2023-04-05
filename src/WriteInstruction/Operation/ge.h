#ifndef __GE__
#define __GE__
#include "operation.h"

class Ge : public Operation {
    string getName() {
        return "ge";
    }
};
#endif