#ifndef __INSTRUCTION__
#define __INSTRUCTION__

class Instruction {
  private:
    string name;
    int argCount;
    
  public:
    virtual string getName() = 0;
    virtual int getArgCount() = 0;

};
#endif