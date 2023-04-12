#ifndef __ASS__
#define __ASS__
#include "writeinstruction.h"
class Ass : public WriteInstruction {
    public:
    Ass() {
        name = "ass";
    }
    string generate(const vector<string>& args) {
        return "";
    }
};
#endif