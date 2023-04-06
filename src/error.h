#ifndef __ERROR__
#define __ERROR__
class Error {
    vector<int> nums;
    string word;
    string errorName;
    const int LINE = 0;
    // instruction:
    //     name not valid
    //     if name is valid, then check for invalid parameters:
        //     wrong number of args
        //     parameters have unassigned variables (Read before written to)
        //     wrong datatype: like passing in a label instead of imm. val or variables
        //     invalid variable name:  ie: 8abb

    // labels:
    //     duplicate labels
    //     labels have other params after it
    public:
    Error() {}
    Error(const vector<int> & v, const string& w, const string& e) {
        nums=v;
        word=w;
        errorName=e;
    }

    string atLine() {
        return "Error: Line "+std::to_string(nums[LINE]+1)+": ";
    }

    string message() {
        string msg = atLine();
        if(errorName=="Label Has Parameters") {
            msg+=errorName+" \""+word+"\"";
        } else if(errorName=="Duplicate Label") {
            msg.pop_back();
            msg.pop_back();
            for(int i = 1; i < nums.size(); i++) {
                msg+=", "+to_string(nums[i]);
            }
            msg+=": "+word+" is a "+errorName;
        } else if(errorName=="Unknown Instruction") {
            msg+=errorName+" \""+word+"\"";
        } else if(errorName=="Parameter Count") {
            msg+=word+" has "+to_string(nums[2])+" arguments; requires "+to_string(nums[1]);
        } else if(errorName=="uninitialized variable") {
            msg+=word+" is uninitialized";
        } else if(errorName=="variable only") {
            msg+="\""+word+"\" (argument "+to_string(nums[1])+") has to be a variable";
        } else if(errorName=="var or num only") {
            msg+="\""+word+"\" (argument "+to_string(nums[1])+") has to be a variable or number";
        } else if(errorName=="labels only") {
            msg+="\""+word+"\" (argument "+to_string(nums[1])+") has to be a label";
        }
        return msg;
    }
};
#endif