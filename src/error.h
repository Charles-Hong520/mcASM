#ifndef __ERROR__
#define __ERROR__
class Error {
    vector<int> lineNumbers;
    string word;
    string errorName;
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

    Error(const vector<int> & v, const string& w, const string& e) {
        lineNumbers=v;
        word=w;
        errorName=e;
    }
};
#endif