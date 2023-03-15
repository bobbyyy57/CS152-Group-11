//#include <stdio.h>
#include <string>
#include <vector>

enum Type { Integer, Array };
struct Node {
    std::string code;
    std::string name;

    Type type;
    std::vector<Type> paramTypes; // Function calls
    std::string index; // Arrays
};