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

#include "Parser.h"

string printAtLine(int n) {
    return "Error: Line "+std::to_string(n)+": ";
}

int main(int argc, char** argv) {
    if(argc != 2 && argc != 3) {
        cerr<<"invalid argument count"<<endl;
        return 1;
    }
    std::ifstream fin(argv[1]);
    string filename;
    if(argc==2) filename = "a.mcfunction";
    else filename = argv[2];
    std::ofstream fout(filename);

    Parser parser;
    parser.parse(fin);
}