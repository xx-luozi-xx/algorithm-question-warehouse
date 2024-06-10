#include "CP_Exception.h"
#include "syntaxTree.h"
#include "CFG_RULE.h"
#include <iostream>

namespace CP{

static void dfs_print_tree(SyntaxNodeBase* node);

SyntaxTree::SyntaxTree(const std::list<Word>& words){
    std::list<Word>::const_iterator itr = words.begin();
    root_ = CFG_program(itr, words.end());
    if(itr != words.end()){
        throw CP::Exception::SYNTAX_ERROR;
    }
}

void SyntaxTree::print_info() const{
    dfs_print_tree(root_);
}

static void dfs_print_tree(SyntaxNodeBase* node){
    std::cout << node->info();
    VariableSyntaxNode* variableSyntaxNode = dynamic_cast<VariableSyntaxNode*>(node);
    if(variableSyntaxNode != nullptr){
        if(variableSyntaxNode->childs().empty() == false){
            std::cout << "(";
            bool commaTag = false;
            for(SyntaxNodeBase* itr : variableSyntaxNode->childs()){
                if(commaTag == true){
                    std::cout << ",";
                }
                dfs_print_tree(itr);
                commaTag = true;
            }
            std::cout << ")";
        }
    }
}

}//namespace