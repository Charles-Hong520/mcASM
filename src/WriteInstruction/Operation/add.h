#ifndef __ADD__
#define __ADD__
#include "operation.h"
class Add : public Operation {
    public:
    Add() {
        name = "add";
    }
    string generate(const vector<string>& args) {
        return "";
        
    }
};
#endif