#include "syntaxNode.h"

namespace CP{

VariableSyntaxNode::VariableSyntaxNode(CP::VariableSyntaxNode::Type syntaxNodeType)
    :syntaxNodeType_(syntaxNodeType), childs_(){
    void();
}

void VariableSyntaxNode::addChilds(SyntaxNodeBase* child){
    childs_.push_back(child);
}


TerminalSyntaxNode::TerminalSyntaxNode(CP::Word::Type lexicalNodeType, std::string value)
    :lexicalNodeType_(lexicalNodeType), value_(value){
    void();
}

}//namespace
