#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::stringstream;
using std::map;
using std::vector;

#include "parser.h"

string printAtLine(int n) {
    return "Error: Line "+std::to_string(n)+": ";
}

int main(int argc, char** argv) {
    if(argc != 2 && argc != 4) {
        cerr<<"invalid argument count"<<endl;
        return 1;
    }
    std::ifstream fin(argv[1]);
    std::ofstream fout("a.mcfunction");
    string line, inst_token;
    Parser parser;
    int lineNumber = 0;
    while(getline(fin, line)) {        
        lineNumber++;
        if(line=="") {
            getline(fin,line);
            continue;
        }
        parser.parse(line);
        //check what instruction it is.
        if(!parser.hasValidName()) {
            cerr<<printAtLine(lineNumber)<<"\""<<parser.getInstName()<<"\" is an invalid instruction"<<endl;
            continue;
        }
        //then check for valid params
        if(!parser.hasValidParamCount()) {
            cerr<<printAtLine(lineNumber)<<"\""<<parser.getInstName()<<"\" requires "<<parser.getArgCount()<<" arguments"<<endl;
            continue;
        }
    }

}