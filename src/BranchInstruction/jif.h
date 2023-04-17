#ifndef __JIF__
#define __JIF__
#include "../instruction.h"
class Jif : public Instruction {
    public:
    Jif() {
        name = "jif";
        argCount = 2;
        reqs = {'v', 'l'};
    }
    string generate(const vector<string>& args, int currln) {
        int jmpTo = std::stoi(args[2]);
        if (currln >= jmpTo) jmpTo--;
        return "";
        
    }
};
#endif