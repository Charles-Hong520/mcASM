#ifndef __INSTRUCTION__
#define __INSTRUCTION__

bool isVariable(const string& str) {
    return (str[0]<='Z' && str[0]>='A') || (str[0]<='z' && str[0]>='a');
}
bool isNumber(const string& str) {
    if(str[0]!='#') return false;
    long long num = 0;
    int i = 1;
    flag = false;
    if(str[1]=='-') i += (flag = true);
    for(; i < str.size(); i++) {
        if(str[i]>'9' || str[i]<'0') return false;
        num *= 10;
        num += str[i]-'0';
    }
    if(flag) num *= -1;
    return num == std::stoll(str);
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
    //virtual string generateMC(const vector<string>& v) = 0;
};
#endif