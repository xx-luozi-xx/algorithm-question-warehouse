#pragma once

#include <string>
#include <vector>

#include "syntaxNode.h"

namespace CP{

class SyntaxTree{
public:
    SyntaxTree(const std::list<Word>& words);
    
    void print_info() const;

private:
    SyntaxNodeBase* root_;
};


}