#pragma once

#include <string>
#include <vector>

#include "SyntaxNode.h"

namespace CP{

class SyntaxTree{
public:
    SyntaxTree(const std::list<Word>& words);
    
    void print_info() const;

private:
    SyntaxNodeBase* root_;
};


}