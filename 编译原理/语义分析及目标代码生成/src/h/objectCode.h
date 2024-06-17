#pragma once
#include <string>

namespace CP{

struct ObjectCode{
    enum Type{
        JMP,
        INT,
        OPR,
        STO,
        LIT,
        LOD,
        JPC,
        CAL,
        
    } type;
    
    int levelDiv;
    int addr;

    ObjectCode(Type codeType, int levelDiv, int addr);

    static std::string TypeToString(Type type);
    static ObjectCode::Type StringToType(const std::string& str);
};


}//namespace



