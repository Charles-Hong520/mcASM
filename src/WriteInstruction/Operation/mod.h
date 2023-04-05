#ifndef __MOD__
#define __MOD__
#include "operation.h"
class Mod : public Operation {
    string getName() {
        return "mod";
    }
};
#endif