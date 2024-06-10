#pragma once
#include <list>

#include "lexical.h"
#include "syntaxTree.h"
#include "syntaxNode.h"

namespace CP{

//<程序>→<分程序>.
SyntaxNodeBase* CFG_program(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <分程序>→ [<常量说明部分>][<变量说明部分>][<过程说明部分>]<语句>
SyntaxNodeBase* CFG_subprog(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <常量说明部分> → CONST<常量定义>{ ,<常量定义>};
SyntaxNodeBase* CFG_constantDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <变量说明部分> → VAR<标识符>{ ,<标识符>};
SyntaxNodeBase* CFG_variableDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <过程说明部分> → <过程首部><分程序>;{<过程说明部分>}
SyntaxNodeBase* CFG_procedureDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <语句> → <赋值语句>|<条件语句>|<当型循环语句>|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<空语句>
SyntaxNodeBase* CFG_sentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <常量定义> → <标识符>=<无符号整数>
SyntaxNodeBase* CFG_constantDefine(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <过程首部> → PROCEDURE <标识符>;
SyntaxNodeBase* CFG_procedureHeader(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <赋值语句> → <标识符>:=<表达式>
SyntaxNodeBase* CFG_assignment(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<条件语句> → IF<条件>THEN<语句>
SyntaxNodeBase* CFG_ifSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<当型循环语句> → WHILE<条件>DO<语句>
SyntaxNodeBase* CFG_whileSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<过程调用语句> → CALL<标识符>
SyntaxNodeBase* CFG_callSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<读语句> → READ(<标识符>{ ,<标识符>})
SyntaxNodeBase* CFG_readSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<写语句> → WRITE(<标识符>{,<标识符>})
SyntaxNodeBase* CFG_writeSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<复合语句> → BEGIN<语句>{ ;<语句>} END
SyntaxNodeBase* CFG_combined(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<空语句> → epsilon
SyntaxNodeBase* CFG_empty(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <表达式> → [+|-]<项>{<加减运算符><项>}
SyntaxNodeBase* CFG_experession(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

// <条件> → <表达式><关系运算符><表达式>|ODD<表达式>
SyntaxNodeBase* CFG_condition(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<项> → <因子>{<乘除运算符><因子>}
SyntaxNodeBase* CFG_item(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);

//<因子> → <标识符>|<无符号整数>|(<表达式>)
SyntaxNodeBase* CFG_factor(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end);


}//namespace

// "PROGRAM",
// "SUBPROG",
// "CONSTANTDECLARE",
// "CONSTANTDEFINE",
// "VARIABLEDECLARE",
// "PROCEDUREDECLARE",
// "PROCEDUREHEAD",
// "SENTENCE",
// "ASSIGNMENT",
// "COMBINED",
// "CONDITION",
// "EXPRESSION",
// "ITEM",
// "FACTOR",
// "IFSENTENCE",
// "CALLSENTENCE",
// "WHILESENTENCE",
// "READSENTENCE",
// "WRITESENTENCE",
// "EMPTY",
// "LP",
// "RP",
// "COMMA"













