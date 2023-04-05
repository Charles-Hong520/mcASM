#ifndef __BITNOT__
#define __BITNOT__
#include "operation.h"

class Bitnot : public Operation {
    string getName() {
        return "bitnot";
    }
};
#endif