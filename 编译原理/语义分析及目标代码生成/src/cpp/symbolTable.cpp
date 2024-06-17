#include "symbolTable.h"
#include "symbol.h"
#include "CP_Exception.h"

#include <iostream>

namespace CP{

std::vector<Symbol>::iterator 
SymbolTable::find(const std::string& symbolName){
    for(auto itr = symbolTable_.begin(); itr != symbolTable_.end(); ++itr){
        if(itr->name == symbolName){
            return itr;
        }
    }
    return symbolTable_.end();
}

void 
SymbolTable::insert(const std::string& symbolName, Symbol::Type symbolType, int value, int thisLevel){
    std::cerr << symbolName << " in level: " << thisLevel << "\n";
    auto itr = find(symbolName);
	if(itr!=symbolTable_.end() and itr->level==thisLevel) {
        throw CP::Exception::SYMBOL_REDECLARE;
	}

	if(symbolType == Symbol::Type::CONSTANT){
        symbolTable_.push_back(Symbol(symbolName, symbolType, value, 0, 0));
    }else if(symbolType == Symbol::Type::VARIABLE){
        symbolTable_.push_back(Symbol(symbolName, symbolType, 0, thisLevel, Dx_++));
    }else if(symbolType == Symbol::Type::PROCEDURE){
        symbolTable_.push_back(Symbol(symbolName, symbolType, 0, thisLevel, 0));
    }
	else{
        throw CP::Exception::SYMBOL_TYPE_ERROR;
	}
}


int 
SymbolTable::getDx()const {
    return Dx_;
}

int 
SymbolTable::setDx(int value){
    Dx_ = value;
}

bool 
SymbolTable::empty()const {
    return symbolTable_.empty();
}

std::vector<Symbol>& 
SymbolTable::data(){
    return symbolTable_;
}


}//namespace 
