#ifndef __INSTRUCTION__
#define __INSTRUCTION__
#define OBJ_VARS "Vars"
#define OBJ_INTERNAL "Internal"
#define ARG1 "__arg1"
#define ARG2 "__arg2"
#define RET "__ret"
bool isVariable(const string& str) {
    return (str[0]<='Z' && str[0]>='A') || (str[0]<='z' && str[0]>='a');
}
bool isNumber(string str) {
    if(str[0]!='#') return false;
    reverse(str.begin(),str.end());
    str.pop_back();
    reverse(str.begin(),str.end());
    long long num = 0;
    int i = 0;
    bool flag = false;
    if(str[0]=='-') i += (flag = true);
    int sz = str.size();
    for(; i < sz; i++) {
        if(str[i]>'9' || str[i]<'0') return false;
        num *= 10;
        num += str[i]-'0';
    }
    if(flag) num *= -1;
    return num == std::stoll(str);
}
string mcAssignVar(const string& LHS, const string& RHS) {
    // for var-var transfer
    // scoreboard players operation __arg1 Internal = <NAME OF VAR> Vars
    return "scoreboard players operation "+LHS+" "+OBJ_INTERNAL+" = "+RHS+" "+OBJ_VARS"\n";
}
string mcAssignImm(const string& LHS, const string& RHS) {
    // for var-var transfer
    //scoreboard players set __arg1 Internal <VALUE>
    return "scoreboard players set "+LHS+" "+OBJ_INTERNAL+" "+RHS+"\n";
}
class Instruction {
protected:
    string name;
    int argCount;
    vector<char> reqs;
public:
    int getArgCount() {return argCount;}
    string getName() {return name;}
    char getReq(int paramIndex) {return reqs[paramIndex];}
    virtual string generate(const vector<string>& args){return "";}
    //virtual string generateMC(const vector<string>& v) = 0;
};
#endif