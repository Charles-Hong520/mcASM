#ifndef __OR__
#define __OR__
#include "operation.h"

class Or : public Operation {
    string getName() {
        return "or";
    }
};
#endif