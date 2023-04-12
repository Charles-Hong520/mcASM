#ifndef __MUL__
#define __MUL__
#include "operation.h"
class Mul : public Operation {
    public:
    Mul() {
        name = "mul";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif