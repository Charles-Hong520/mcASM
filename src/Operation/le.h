#ifndef __LE__
#define __LE__
#include "operation.h"

class Le : public Operation {
    string getName() {
        return "le";
    }
};
#endif