#ifndef __BITNOT__
#define __BITNOT__
#include "writeinstruction.h"
class Bitnot : public WriteInstruction {
    public:
    Bitnot() {
        name = "bitnot";
    }
    // string generate(const vector<string>& args) {
    //     return "";

    // }
};
#endif