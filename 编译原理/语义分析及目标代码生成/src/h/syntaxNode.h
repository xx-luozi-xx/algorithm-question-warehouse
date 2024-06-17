#pragma once
#include <string>
#include <list>

#include "lexical.h"

namespace CP{

class SyntaxNodeBase{
public:
    virtual std::string info()const = 0;
};

class TerminalSyntaxNode : public SyntaxNodeBase{
public: 
    TerminalSyntaxNode(CP::Word::Type lexicalNodeType, std::string value);

    virtual std::string info()const override;

private:
    CP::Word::Type lexicalNodeType_;
    std::string value_;
};

class VariableSyntaxNode : public SyntaxNodeBase{
public:
    enum Type{
        PROGRAM, 
        SUBPROG, 
        CONSTANTDECLARE, 
        VAIRABLEDECLARE,
        PROCEDUREDECLARE,
        SENTENCE,
        CONSTANTDEFINE,
        PROCEDUREHEAD,
        ASSIGNMENT,
        IFSENTENCE,
        WHILESENTENCE,
        CALLSENTENCE,
        READSENTENCE,
        WRITESENTENCE,
        COMBINED,
        EMPTY,
        EXPRESSION,
        CONDITION,
        ITEM,
        FACTOR,

    };
    static std::string typeToString(VariableSyntaxNode::Type syntaxNodetype);

public:
    VariableSyntaxNode(CP::VariableSyntaxNode::Type syntaxNodeType);
    void addChilds(SyntaxNodeBase* child);
    const std::list<SyntaxNodeBase*>& childs() const;

    virtual std::string info()const override;

private:
    CP::VariableSyntaxNode::Type syntaxNodeType_;
    std::list<SyntaxNodeBase*> childs_;
};


}//namespace
