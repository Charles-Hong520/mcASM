#ifndef __BITAND__
#define __BITAND__
#include "operation.h"
class Bitand : public Operation {
    public:
    Bitand() {
        name = "bitand";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif