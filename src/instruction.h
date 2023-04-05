#ifndef __INSTRUCTION__
#define __INSTRUCTION__

class Instruction {
  protected:
    string name;
    int argCount;
    
  public:
    int getArgCount() {return argCount;}
    string getName() {return name;}
    //virtual string generateMC(const vector<string>& v) = 0;
};
#endif