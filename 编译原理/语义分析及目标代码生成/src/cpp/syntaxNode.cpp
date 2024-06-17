#include "syntaxNode.h"

namespace CP{

std::string 
VariableSyntaxNode::typeToString(VariableSyntaxNode::Type syntaxNodetype){
    switch (syntaxNodetype){
    case PROGRAM : 
        return "PROGRAM";
    case SUBPROG : 
        return "SUBPROG";
    case CONSTANTDECLARE : 
        return "CONSTANTDECLARE";
    case VAIRABLEDECLARE : 
        return "VARIABLEDECLARE";
    case PROCEDUREDECLARE : 
        return "PROCEDUREDECLARE";
    case SENTENCE : 
        return "SENTENCE";
    case CONSTANTDEFINE : 
        return "CONSTANTDEFINE";
    case PROCEDUREHEAD : 
        return "PROCEDUREHEAD";
    case ASSIGNMENT : 
        return "ASSIGNMENT";
    case IFSENTENCE : 
        return "IFSENTENCE";
    case WHILESENTENCE : 
        return "WHILESENTENCE";
    case CALLSENTENCE : 
        return "CALLSENTENCE";
    case READSENTENCE : 
        return "READSENTENCE";
    case WRITESENTENCE : 
        return "WRITESENTENCE";
    case COMBINED : 
        return "COMBINED";
    case EMPTY : 
        return "EMPTY";
    case EXPRESSION : 
        return "EXPRESSION";
    case CONDITION : 
        return "CONDITION";
    case ITEM : 
        return "ITEM";
    case FACTOR : 
        return "FACTOR";
    
    default: assert(0);
        break;
    }
}


VariableSyntaxNode::VariableSyntaxNode(CP::VariableSyntaxNode::Type syntaxNodeType)
    :syntaxNodeType_(syntaxNodeType), childs_(){
    void();
}

void VariableSyntaxNode::addChilds(SyntaxNodeBase* child){
    childs_.push_back(child);
}

const std::list<SyntaxNodeBase*>& 
VariableSyntaxNode::childs() const{
    return childs_;
}

std::string 
VariableSyntaxNode::info()const{
    return typeToString(syntaxNodeType_);
}



TerminalSyntaxNode::TerminalSyntaxNode(CP::Word::Type lexicalNodeType, std::string value)
    :lexicalNodeType_(lexicalNodeType), value_(value){
    void();
}

std::string 
TerminalSyntaxNode::info()const{
    if(value_ == ","){
        return "COMMA";
    }else if(value_ == "("){
        return "LP";
    }else if(value_ == ")"){
        return "RP";
    }else{
        return value_;
    }
    //todo number with out leading zero
}


}//namespace
