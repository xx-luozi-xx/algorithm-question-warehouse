#pragma once 

#include <string>

namespace CP{

struct Symbol{
    std::string name;
    
    enum Type{
        CONSTANT,
        VARIABLE,
        PROCEDURE,
    } type;

    int value;
    int level;
    int addr;

    Symbol(const std::string& symbolName, Type SymbolType, int value, int level, int addr);
    Symbol() = default;
};


}//namespace

