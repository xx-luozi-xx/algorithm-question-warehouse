#include "objectCode.h"
#include "CP_Exception.h"

namespace CP{
ObjectCode::ObjectCode(Type codeType, int levelDiv, int addr)
    :type(codeType), levelDiv(levelDiv), addr(addr)
{
    void();
}

std::string ObjectCode::TypeToString(Type type){
    switch (type){
    case JMP: return "JMP";
    case INT: return "INT";
    case OPR: return "OPR";
    case STO: return "STO";
    case LIT: return "LIT";
    case LOD: return "LOD";
    case JPC: return "JPC";
    case CAL: return "CAL";

    default:
        throw CP::Exception::OBJECT_CODE_TYOE_ERROR;
    }
}

ObjectCode::Type ObjectCode::StringToType(const std::string& str){
    if(str == "JMP"){
        return Type::JMP;
    }else if(str == "INT"){
        return Type::INT;
    }else if(str == "OPR"){
        return Type::OPR;
    }else if(str == "STO"){
        return Type::STO;
    }else if(str == "LIT"){
        return Type::LIT;
    }else if(str == "LOD"){
        return Type::LOD;
    }else if(str == "JPC"){
        return Type::JPC;
    }else if(str == "CAL"){
        return Type::CAL;
    }else{
        throw CP::Exception::OBJECT_CODE_TYOE_ERROR;
    }
}

}//namespace