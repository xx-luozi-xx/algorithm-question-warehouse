#include "CP_Exception.h"
#include "syntaxTree.h"
#include "CFG_RULE.h"

namespace CP{

SyntaxTree::SyntaxTree(const std::list<Word>& words){
    std::list<Word>::const_iterator itr = words.begin();
    root_ = CFG_program(itr, words.end());
    if(itr != words.end()){
        throw CP::Exception::SYNTAX_ERROR;
    }
}

}//namespace