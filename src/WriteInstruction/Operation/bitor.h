#ifndef __BITOR__
#define __BITOR__
#include "operation.h"
class Bitor : public Operation {
    public:
    Bitor() {
        name = "bitor";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif