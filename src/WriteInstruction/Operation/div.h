#ifndef __DIV__
#define __DIV__
#include "operation.h"
class Div : public Operation {
    public:
    Div() {
        name = "div";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif