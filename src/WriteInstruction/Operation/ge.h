#ifndef __GE__
#define __GE__
#include "operation.h"

class Ge : public Operation {
    public:
    Ge() {
        name = "ge";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif