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
    Parser parser;









}