#include "symbol.h"

namespace CP{

Symbol::Symbol(const std::string& symbolName, Type SymbolType, int value, int level, int addr)
    :name(symbolName), type(SymbolType), value(value), level(level), addr(addr)
{
    void();
}


}//namesapce


