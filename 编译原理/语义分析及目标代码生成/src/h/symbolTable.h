#pragma once
#include <string>
#include <vector>

#include "symbol.h"

namespace CP{


class SymbolTable{
public:
std::vector<Symbol>::iterator 
find(const std::string& symbolName);

void 
insert(const std::string& symbolName, Symbol::Type symbolType, int value, int thisLevel);

int getDx()const ;
int setDx(int value);

bool empty()const ;

std::vector<Symbol>& data();

private:
    std::vector<Symbol> symbolTable_;
    int Dx_ = 3;	

};




}//namespace



