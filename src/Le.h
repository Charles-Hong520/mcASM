#ifndef __LE__
#define __LE__
#include "instruction.h"
class Le : public Instruction {
    int getArgCount() {
        return 3;
    }
    string getName() {
        return "le";
    }
};
#endif