#include "CFG_RULE.h"
#include "CP_Exception.h"

namespace CP{

SyntaxNodeBase* CFG_program(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<程序>→<分程序>.
    VariableSyntaxNode* programNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::PROGRAM);
    
    //<分程序>
    SyntaxNodeBase* subprogNode = CFG_subprog(itr, itr_end);
    programNode->addChilds(subprogNode);

    //.
    if(itr != itr_end and itr->value()=="."){
        SyntaxNodeBase* dotTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        programNode->addChilds(dotTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return programNode;
}

SyntaxNodeBase* CFG_subprog(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <分程序>→ [<常量说明部分>][<变量说明部分>][<过程说明部分>]<语句>
    VariableSyntaxNode* subprogNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::SUBPROG);

    //[<常量说明部分>]
    if(itr != itr_end and itr->value()=="CONST"){
        SyntaxNodeBase* constantDeclareNode = CFG_constantDeclare(itr, itr_end);
        subprogNode->addChilds(constantDeclareNode);
    }

    //[<变量说明部分>]
    if(itr != itr_end and itr->value()=="VAR"){
        SyntaxNodeBase* variableDeclareNode = CFG_variableDeclare(itr, itr_end);
        subprogNode->addChilds(variableDeclareNode);
    }

    //[<过程说明部分>]
    if(itr != itr_end and itr->value()=="PROCEDURE"){
        SyntaxNodeBase* procedureDeclareNode = CFG_procedureDeclare(itr, itr_end);
        subprogNode->addChilds(procedureDeclareNode);
    }

    //<语句>
    SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
    subprogNode->addChilds(sentenceNode);

    return subprogNode;
}

SyntaxNodeBase* CFG_constantDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <常量说明部分> → CONST<常量定义>{ ,<常量定义>};
    VariableSyntaxNode* constantDeclareNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::CONSTANTDECLARE);

    //CONST
    if(itr != itr_end and itr->value()=="CONST"){
        SyntaxNodeBase* constTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDeclareNode->addChilds(constTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }    

    //<常量定义>
    SyntaxNodeBase* constantDefineNode = CFG_constantDefine(itr, itr_end);
    constantDeclareNode->addChilds(constantDefineNode);

    //{ ,<常量定义>}
    while(itr != itr_end and itr->value()==","){
        //,
        SyntaxNodeBase* commaTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDeclareNode->addChilds(commaTerminalNode);

        //<常量定义>
        SyntaxNodeBase* constantDefineNode = CFG_constantDefine(itr, itr_end);
        constantDeclareNode->addChilds(constantDefineNode);
    }

    //;
    if(itr != itr_end and itr->value()==";"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDeclareNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    return constantDeclareNode;
}

SyntaxNodeBase* CFG_variableDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <变量说明部分> → VAR<标识符>{ ,<标识符>};
    VariableSyntaxNode* variableDeclareNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::VAIRABLEDECLARE);

    //VAR
    if(itr != itr_end and itr->value()=="VAR"){
        SyntaxNodeBase* varTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        variableDeclareNode->addChilds(varTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }    

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        variableDeclareNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    //{ ,<标识符>}
    while(itr != itr_end and itr->value()==","){
        //,
        SyntaxNodeBase* commaTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        variableDeclareNode->addChilds(commaTerminalNode);

        //<标识符>
        if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
            SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            variableDeclareNode->addChilds(identifierTerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        } 
    }
    
    //;
    if(itr != itr_end and itr->value()==";"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        variableDeclareNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    return variableDeclareNode;
}

SyntaxNodeBase* CFG_procedureDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
    static int enterCounter = 0;
    enterCounter ++;
    if(enterCounter > 3){
        throw CP::Exception::SYNTAX_ERROR;
    }
// <过程说明部分> → <过程首部><分程序>;{<过程说明部分>}
    VariableSyntaxNode* procedureDeclareNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::PROCEDUREDECLARE);

    // <过程首部>
    SyntaxNodeBase* procedureHeaderNode = CFG_procedureHeader(itr, itr_end);
    procedureDeclareNode->addChilds(procedureHeaderNode);    
    
    // <分程序>
    SyntaxNodeBase* subprogNode = CFG_subprog(itr, itr_end);
    procedureDeclareNode->addChilds(subprogNode);

    // ;
    if(itr != itr_end and itr->value()==";"){
        SyntaxNodeBase* semicolonsTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        procedureDeclareNode->addChilds(semicolonsTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }  

    enterCounter --;

    // {<过程说明部分>}
    while(itr != itr_end and itr->value()=="PROCEDURE"){
        SyntaxNodeBase* childProcedureDeclareNode = CFG_procedureDeclare(itr, itr_end);
        procedureDeclareNode->addChilds(childProcedureDeclareNode);  
    }

    return procedureDeclareNode;
}

SyntaxNodeBase* CFG_sentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <语句> → <赋值语句>|<条件语句>|<当型循环语句>|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<空语句>
    VariableSyntaxNode* sentenceNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::PROCEDUREDECLARE);
    
    auto itr_next = itr;
    if(itr_next != itr_end){
        itr_next ++;
    }

    //<赋值语句>
    if(itr != itr_end and itr->type() == CP::Word::Type::IDENTIFIER
        and itr_next != itr_end and itr_next->value() == ":="){
            
        SyntaxNodeBase* assignmentNode = CFG_assignment(itr, itr_end);
        sentenceNode->addChilds(assignmentNode);  
    }
    //<条件语句>
    else if (itr != itr_end and itr->value() == "IF"){
        SyntaxNodeBase* ifSentenceNode = CFG_ifSentence(itr, itr_end);
        sentenceNode->addChilds(ifSentenceNode);          
    }
    //<当型循环语句>
    else if (itr != itr_end and itr->value() == "WHILE"){
        SyntaxNodeBase* whileSentenceNode = CFG_whileSentence(itr, itr_end);
        sentenceNode->addChilds(whileSentenceNode);       
    }
    //<过程调用语句>
    else if (itr != itr_end and itr->value() == "CALL"){
        SyntaxNodeBase* callSentenceNode = CFG_callSentence(itr, itr_end);
        sentenceNode->addChilds(callSentenceNode);   
    }
    //<读语句>
    else if (itr != itr_end and itr->value() == "READ"){
        SyntaxNodeBase* readSentenceNode = CFG_readSentence(itr, itr_end);
        sentenceNode->addChilds(readSentenceNode);
    }
    //<写语句>
    else if (itr != itr_end and itr->value() == "WRITE"){
        SyntaxNodeBase* writeSentenceNode = CFG_writeSentence(itr, itr_end);
        sentenceNode->addChilds(writeSentenceNode);
    }
    //<复合语句>
    else if (itr != itr_end and itr->value() == "BEGIN"){
        SyntaxNodeBase* combinedNode = CFG_combined(itr, itr_end);
        sentenceNode->addChilds(combinedNode);
    }
    //<空语句>
    else{
        SyntaxNodeBase* emptyNode = CFG_empty(itr, itr_end);
        sentenceNode->addChilds(emptyNode);
    }
    
    return sentenceNode;
}

SyntaxNodeBase* CFG_constantDefine(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <常量定义> → <标识符>=<无符号整数>
    VariableSyntaxNode* constantDefineNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::CONSTANTDEFINE);

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDefineNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    // =
    if(itr != itr_end and itr->value()=="="){
        SyntaxNodeBase* equalTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDefineNode->addChilds(equalTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <无符号整数>
    if(itr != itr_end and itr->type()==CP::Word::Type::NUMBER){
        SyntaxNodeBase* numberTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDefineNode->addChilds(numberTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return constantDefineNode;
}

SyntaxNodeBase* CFG_procedureHeader(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <过程首部> → PROCEDURE <标识符>;
    VariableSyntaxNode* procedureHeaderNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::PROCEDUREHEAD);

    //PROCEDURE
    if(itr != itr_end and itr->value()=="PROCEDURE"){
        SyntaxNodeBase* procedureTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        procedureHeaderNode->addChilds(procedureTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        procedureHeaderNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 
    
    //;
    if(itr != itr_end and itr->value()==";"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        procedureHeaderNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return procedureHeaderNode;
}

SyntaxNodeBase* CFG_assignment(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <赋值语句> → <标识符>:=<表达式>
    VariableSyntaxNode* assignmentNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::ASSIGNMENT);

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        assignmentNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    //:=
    if(itr != itr_end and itr->value()==":="){
        SyntaxNodeBase* assignOperatorTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        assignmentNode->addChilds(assignOperatorTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <表达式>
    SyntaxNodeBase* experessionNode = CFG_experession(itr, itr_end);
    assignmentNode->addChilds(experessionNode);    

    return assignmentNode;    
}

SyntaxNodeBase* CFG_ifSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<条件语句> → IF<条件>THEN<语句>
    VariableSyntaxNode* ifSentenceNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::IFSENTENCE);

    //IF
    if(itr != itr_end and itr->value()=="IF"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        ifSentenceNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <条件>
    SyntaxNodeBase* conditionNode = CFG_condition(itr, itr_end);
    ifSentenceNode->addChilds(conditionNode);

    //THEN
    if(itr != itr_end and itr->value()=="THEN"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        ifSentenceNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <语句>
    SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
    ifSentenceNode->addChilds(sentenceNode);

    return ifSentenceNode;
}

SyntaxNodeBase* CFG_whileSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<当型循环语句> → WHILE<条件>DO<语句>
    VariableSyntaxNode* whileSentenceNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::WHILESENTENCE);

    //WHILE
    if(itr != itr_end and itr->value()=="WHILE"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        whileSentenceNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <条件>
    SyntaxNodeBase* conditionNode = CFG_condition(itr, itr_end);
    whileSentenceNode->addChilds(conditionNode);

    //DO
    if(itr != itr_end and itr->value()=="DO"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        whileSentenceNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <语句>
    SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
    whileSentenceNode->addChilds(sentenceNode);

    return whileSentenceNode;    
}

SyntaxNodeBase* CFG_callSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<过程调用语句> → CALL<标识符>
    VariableSyntaxNode* callSentenceNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::CALLSENTENCE);

    //CALL
    if(itr != itr_end and itr->value()=="CALL"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        callSentenceNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        callSentenceNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    return callSentenceNode;    
}


}//namespace
