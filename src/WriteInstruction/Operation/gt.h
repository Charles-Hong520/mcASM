#ifndef __GT__
#define __GT__
#include "operation.h"

class Gt : public Operation {
    public:
    Gt() {
        name = "gt";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif