#ifndef __AND__
#define __AND__
#include "operation.h"
class And : public Operation {
    public:
    And() {
        name = "and";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif