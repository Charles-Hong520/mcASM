#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <filesystem>

namespace fs = std::filesystem;
using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::stringstream;
using std::map;
using std::vector;
using std::set;
using std::to_string;

#include "Parser.h"



int main(int argc, char** argv) {
    if(argc != 2) {
        cerr<<"invalid argument count"<<endl;
        return 1;
    }
    std::ifstream fin(argv[1]);
    Parser parser;
    if(!parser.parse(fin)) {
        parser.printErrors();
        return 1;
    }
    parser.generateMcfunctionFiles();
}