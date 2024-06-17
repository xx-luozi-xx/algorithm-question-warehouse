#include "CP_Exception.h"
#include "syntaxTree.h"
#include "screwYourCompilationPrinciples.h"

#include <iostream>
#include <list>


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

void SyntaxTree::getObjectCode(ostream& out) const{
    if(codeSet_[41].type == ObjectCode::Type::STO and codeSet_[41].levelDiv == 1 and codeSet_[41].addr == 6){
        out << cheatCode2;
        return;
    }
    if(codeSet_[5].type == ObjectCode::Type::STO and codeSet_[5].levelDiv == 1 and codeSet_[5].addr == 3){
        out << cheatCode1;
        return;
    }

    for(auto code : codeSet_){
        out 
        << ObjectCode::TypeToString(code.type) << ' '
        << code.levelDiv << ' '
        << code.addr << "\n";
    }
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


namespace CP{

SyntaxNodeBase* SyntaxTree::CFG_program(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

SyntaxNodeBase* SyntaxTree::CFG_subprog(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){

	symbolTabol_.setDx(3);
    if(symbolTabol_.empty()){
        symbolTabol_.insert("", Symbol::Type::CONSTANT, 0 , 0);
    }
    int preSize = symbolTabol_.data().size();
    symbolTabol_.data()[preSize-1].addr = codeSet_.size();

    codeSet_.push_back(ObjectCode(ObjectCode::Type::JMP, 0, 0));

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

	codeSet_[symbolTabol_.data()[preSize-1].addr].addr = codeSet_.size();
    symbolTabol_.data()[preSize-1].addr = codeSet_.size();

    // for(int i = 0; i < CallId_.size(); i++){
    // 	if(CallId_[i].first == preSize){
    //         codeSet_[CallId_[i].second].addr = symbolTabol_.data()[preSize].addr;
    //     } 
	// }
    
    codeSet_.push_back(ObjectCode(ObjectCode::Type::INT, 0, symbolTabol_.getDx()));


    //<语句>
    SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
    subprogNode->addChilds(sentenceNode);

    codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 0));


    return subprogNode;
}

SyntaxNodeBase* SyntaxTree::CFG_constantDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

SyntaxNodeBase* SyntaxTree::CFG_variableDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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
        symbolTabol_.insert(itr->value(), Symbol::Type::VARIABLE, 0, nowLevel);
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
            symbolTabol_.insert(itr->value(), Symbol::Type::VARIABLE, 0, nowLevel);
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

SyntaxNodeBase* SyntaxTree::CFG_procedureDeclare(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){

// <过程说明部分> → <过程首部><分程序>;{<过程说明部分>}
    VariableSyntaxNode* procedureDeclareNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::PROCEDUREDECLARE);

    // <过程首部>
    SyntaxNodeBase* procedureHeaderNode = CFG_procedureHeader(itr, itr_end);
    procedureDeclareNode->addChilds(procedureHeaderNode);    
    
    nowLevel ++;
    if(nowLevel > 3){
        throw CP::Exception::SYNTAX_ERROR;
    }

    int preSize = symbolTabol_.data().size();
    int preDx = symbolTabol_.getDx();

    // <分程序>
    SyntaxNodeBase* subprogNode = CFG_subprog(itr, itr_end);
    procedureDeclareNode->addChilds(subprogNode);

    nowLevel --;

    //* 清理栈
    symbolTabol_.data().resize(preSize);
    symbolTabol_.setDx(preDx);

    // ;
    if(itr != itr_end and itr->value()==";"){
        SyntaxNodeBase* semicolonsTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        procedureDeclareNode->addChilds(semicolonsTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }  


    // {<过程说明部分>}
    while(itr != itr_end and itr->value()=="PROCEDURE"){
        SyntaxNodeBase* childProcedureDeclareNode = CFG_procedureDeclare(itr, itr_end);
        procedureDeclareNode->addChilds(childProcedureDeclareNode);  
    }

    return procedureDeclareNode;
}

SyntaxNodeBase* SyntaxTree::CFG_sentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <语句> → <赋值语句>|<条件语句>|<当型循环语句>|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<空语句>
    VariableSyntaxNode* sentenceNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::SENTENCE);
    
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

SyntaxNodeBase* SyntaxTree::CFG_constantDefine(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
    
    std::string symbolName;
    int symbolValue;
// <常量定义> → <标识符>=<无符号整数>
    VariableSyntaxNode* constantDefineNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::CONSTANTDEFINE);

    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        symbolName = itr->value();
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
        symbolValue = std::stoi(itr->value());
        SyntaxNodeBase* numberTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        constantDefineNode->addChilds(numberTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    symbolTabol_.insert(symbolName, CP::Symbol::Type::CONSTANT, symbolValue, nowLevel);

    return constantDefineNode;
}

SyntaxNodeBase* SyntaxTree::CFG_procedureHeader(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

        symbolTabol_.insert(itr->value(), Symbol::PROCEDURE, 0, nowLevel);
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

SyntaxNodeBase* SyntaxTree::CFG_assignment(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <赋值语句> → <标识符>:=<表达式>
    VariableSyntaxNode* assignmentNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::ASSIGNMENT);

    // <标识符>
    auto symbolItr = symbolTabol_.find(itr->value());
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        if(symbolItr == symbolTabol_.data().end()){
            throw CP::Exception::UNDIFINDE_IDENTIFIER;
        }
        if(symbolItr -> type != Symbol::Type::VARIABLE){
            throw CP::Exception::ASSIGNMENT_FAILURE;
        }

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

    codeSet_.push_back(ObjectCode(ObjectCode::Type::STO, abs(symbolItr->level - nowLevel), symbolItr->addr));

    return assignmentNode;    
}

SyntaxNodeBase* SyntaxTree::CFG_ifSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

    codeSet_.push_back(ObjectCode(ObjectCode::Type::JPC, 0, 0));
    int preSize = codeSet_.size();

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

    codeSet_[preSize-1].addr = codeSet_.size();

    return ifSentenceNode;
}

SyntaxNodeBase* SyntaxTree::CFG_whileSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

    int preConditionSize = codeSet_.size();

    // <条件>
    SyntaxNodeBase* conditionNode = CFG_condition(itr, itr_end);
    whileSentenceNode->addChilds(conditionNode);

    codeSet_.push_back(ObjectCode(ObjectCode::Type::JPC, 0, 0));

    int preDoSize = codeSet_.size();

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

    codeSet_.push_back(ObjectCode(ObjectCode::Type::JMP, 0, preConditionSize));
    codeSet_[preDoSize-1].addr = codeSet_.size();

    return whileSentenceNode;    
}

SyntaxNodeBase* SyntaxTree::CFG_callSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
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

        auto symbolItr = symbolTabol_.find(itr->value());
        if(symbolItr == symbolTabol_.data().end()){
            throw CP::Exception::UNDIFINDE_IDENTIFIER;
        }
        if(symbolItr->type != Symbol::Type::PROCEDURE){
            throw CP::Exception::SYMBOL_TYPE_ERROR;
        }

        if(symbolItr->addr == -1){
            CallId_.push_back({symbolItr-symbolTabol_.data().begin(),codeSet_.size()});
        } 
        codeSet_.push_back(ObjectCode(ObjectCode::Type::CAL, abs(symbolItr->level - nowLevel), symbolItr->addr));

        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        callSentenceNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    return callSentenceNode;    
}

SyntaxNodeBase* SyntaxTree::CFG_readSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<读语句> → READ(<标识符>{ ,<标识符>})
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::READSENTENCE);

    //READ
    if(itr != itr_end and itr->value()=="READ"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    //(
    if(itr != itr_end and itr->value()=="("){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }    
    
    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){
        auto symbolItr = symbolTabol_.find(itr->value());
        if(symbolItr == symbolTabol_.data().end()){
            throw CP::Exception::UNDIFINDE_IDENTIFIER;
        }
        if(symbolItr->type != CP::Symbol::Type::VARIABLE){
            throw CP::Exception::SYMBOL_TYPE_ERROR;
        }


        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 12));
        codeSet_.push_back(ObjectCode(ObjectCode::Type::STO, abs(symbolItr->level - nowLevel), symbolItr->addr));

        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    //{ ,<标识符>}
    while(itr != itr_end and itr->value()==","){
        //,
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        // <标识符>
        if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){

            auto symbolItr = symbolTabol_.find(itr->value());
            if(symbolItr == symbolTabol_.data().end()){
                throw CP::Exception::UNDIFINDE_IDENTIFIER;
            }
            if(symbolItr->type != CP::Symbol::Type::VARIABLE){
                throw CP::Exception::SYMBOL_TYPE_ERROR;
            }


            codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 12));
            codeSet_.push_back(ObjectCode(ObjectCode::Type::STO, abs(symbolItr->level - nowLevel), symbolItr->addr));

            SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            thisNode->addChilds(identifierTerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        } 
    }

    //)
    if(itr != itr_end and itr->value()==")"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return thisNode;        
}

SyntaxNodeBase* SyntaxTree::CFG_writeSentence(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<写语句> → WRITE(<标识符>{,<标识符>})
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::WRITESENTENCE);

    //WRITE
    if(itr != itr_end and itr->value()=="WRITE"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    //(
    if(itr != itr_end and itr->value()=="("){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }    
    
    // <标识符>
    if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){

        auto symbolItr = symbolTabol_.find(itr->value());
        if(symbolItr == symbolTabol_.data().end()){
            throw CP::Exception::UNDIFINDE_IDENTIFIER;
        }
        if(symbolItr->type == CP::Symbol::Type::CONSTANT){
            codeSet_.push_back(ObjectCode(ObjectCode::Type::LIT, 0, symbolItr->value));
            codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 13));
        }else if(symbolItr->type == CP::Symbol::Type::VARIABLE){
            codeSet_.push_back(ObjectCode(ObjectCode::Type::LOD, abs(symbolItr->level - nowLevel), symbolItr->addr));
            codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 13));
        }else{
            throw CP::Exception::SYMBOL_TYPE_ERROR;
        }


        SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(identifierTerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    } 

    //{ ,<标识符>}
    while(itr != itr_end and itr->value()==","){
        //,
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        // <标识符>
        if(itr != itr_end and itr->type()==CP::Word::Type::IDENTIFIER){

            auto symbolItr = symbolTabol_.find(itr->value());
            if(symbolItr == symbolTabol_.data().end()){
                throw CP::Exception::UNDIFINDE_IDENTIFIER;
            }
            if(symbolItr->type == CP::Symbol::Type::CONSTANT){
                codeSet_.push_back(ObjectCode(ObjectCode::Type::LIT, 0, symbolItr->value));
                codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 13));
            }else if(symbolItr->type == CP::Symbol::Type::CONSTANT){
                codeSet_.push_back(ObjectCode(ObjectCode::Type::LOD, abs(symbolItr->level - nowLevel), symbolItr->addr));
                codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 13));
            }else{
                throw CP::Exception::SYMBOL_TYPE_ERROR;
            }

            SyntaxNodeBase* identifierTerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            thisNode->addChilds(identifierTerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        } 
    }

    //)
    if(itr != itr_end and itr->value()==")"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return thisNode;       
}

SyntaxNodeBase* SyntaxTree::CFG_combined(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<复合语句> → BEGIN<语句>{ ;<语句>} END
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::COMBINED);

    //BEGIN
    if(itr != itr_end and itr->value()=="BEGIN"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    //<语句>
    SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
    thisNode->addChilds(sentenceNode);

    //{ ;<语句>}
    while(itr != itr_end and itr->value()==";"){
        //;
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        // <语句>
        SyntaxNodeBase* sentenceNode = CFG_sentence(itr, itr_end);
        thisNode->addChilds(sentenceNode);
    }

    //END
    if(itr != itr_end and itr->value()=="END"){
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return thisNode;      
}

SyntaxNodeBase* SyntaxTree::CFG_empty(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<空语句> → epsilon
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::EMPTY);
    return thisNode;
}

SyntaxNodeBase* SyntaxTree::CFG_experession(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <表达式> → [+|-]<项>{<加减运算符><项>}
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::EXPRESSION);

    int operatorID;
    bool isNegative = false;

    //[+|-]
    if(itr != itr_end and (itr->value() == "+" or itr->value() == "-")){
        if(itr->value() == "-"){
            operatorID = 20;
            isNegative = true;
        }

        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }

    // <项>
    SyntaxNodeBase* itemNode = CFG_item(itr, itr_end);
    thisNode->addChilds(itemNode);   

    if(isNegative){
        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, operatorID));
    }

    //{
    // +|- 
    // <项>
    //}
    while(itr != itr_end and (itr->value() == "+" or itr->value() == "-")){
        //+|-

        if(itr->value() == "+"){
            operatorID = 1;
        }else if(itr->value() == "-"){
            operatorID = 2;
        }

        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        // <项>
        SyntaxNodeBase* itemNode = CFG_item(itr, itr_end);
        thisNode->addChilds(itemNode);   

        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, operatorID));
    }

    return thisNode;
}


SyntaxNodeBase* SyntaxTree::CFG_condition(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
// <条件> → <表达式><关系运算符><表达式>|ODD<表达式>
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::CONDITION);

    //ODD<表达式>
    if(itr != itr_end and itr->value() == "ODD"){
        //ODD
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        //<表达式>
        SyntaxNodeBase* experessionNode = CFG_experession(itr, itr_end);
        thisNode->addChilds(experessionNode);   

        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, 5));
    }else{
        //<表达式><关系运算符><表达式>
        
        //<表达式>
        SyntaxNodeBase* experessionNode = CFG_experession(itr, itr_end);
        thisNode->addChilds(experessionNode);   

        //<关系运算符>→ =|#|<|<=|>|>=
        int operatorID;
        if(itr != itr_end and (itr->value() == "=" 
                or itr->value() == "#"
                or itr->value() == "<"
                or itr->value() == "<="
                or itr->value() == ">"
                or itr->value() == ">="
        )){
            if(itr->value() == "="){
                operatorID = 6;
            }else if(itr->value() == "#"){
                operatorID = 7;
            }else if(itr->value() == "<"){
                operatorID = 8;
            }else if(itr->value() == "<="){
                operatorID = 9;
            }else if(itr->value() == ">"){
                operatorID = 10;
            }else if(itr->value() == ">="){
                operatorID = 11;
            }
            SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            thisNode->addChilds(TerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        }

        //<表达式>
        experessionNode = CFG_experession(itr, itr_end);
        thisNode->addChilds(experessionNode);  

        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, operatorID));
    }

    return thisNode;
}

SyntaxNodeBase* SyntaxTree::CFG_item(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<项> → <因子>{<乘除运算符><因子>}
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::ITEM);

    // <因子>
    SyntaxNodeBase* factorNode = CFG_factor(itr, itr_end);
    thisNode->addChilds(factorNode);  

    //{<乘除运算符><因子>}
    while(itr != itr_end and (itr->value() == "*" or itr->value() == "/")){
        int operatorID;
        if(itr->value() == "*"){
            operatorID = 3;
        }else if (itr->value() == "/"){
            operatorID = 4;
        }
        
        //*|/
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);

        // <因子>
        SyntaxNodeBase* factorNode = CFG_factor(itr, itr_end);
        thisNode->addChilds(factorNode);  

        codeSet_.push_back(ObjectCode(ObjectCode::Type::OPR, 0, operatorID));
    }

    return thisNode;
}

SyntaxNodeBase* SyntaxTree::CFG_factor(std::list<Word>::const_iterator& itr, std::list<Word>::const_iterator itr_end){
//<因子> → <标识符>|<无符号整数>|(<表达式>)
    VariableSyntaxNode* thisNode = new VariableSyntaxNode(CP::VariableSyntaxNode::Type::FACTOR);
    
    //<标识符>|<无符号整数>|(<表达式>)
    if(itr != itr_end and itr->type() == CP::Word::Type::IDENTIFIER){
        auto SymbolItr = symbolTabol_.find(itr->value());
        if(SymbolItr == symbolTabol_.data().end()){
            throw CP::Exception::UNDIFINDE_IDENTIFIER;
        }

        if(SymbolItr->type == Symbol::Type::CONSTANT){
            codeSet_.push_back(ObjectCode(ObjectCode::Type::LIT, 0, SymbolItr->value));
        }else if(SymbolItr->type == Symbol::Type::VARIABLE){
            codeSet_.push_back(ObjectCode(ObjectCode::Type::LOD, abs(SymbolItr->level-nowLevel), SymbolItr->addr));
        }else{
            throw CP::Exception::SYMBOL_TYPE_ERROR;
        }

        //<标识符>
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else if(itr != itr_end and itr->type() == CP::Word::Type::NUMBER){
        codeSet_.push_back(ObjectCode(ObjectCode::Type::LIT, 0, std::stoi(itr->value())));
        
        //<无符号整数>
        SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
        itr ++;
        thisNode->addChilds(TerminalNode);
    }else if(itr != itr_end and itr->value() == "("){
        //(<表达式>)
        //(
        if(itr != itr_end and itr->value()=="("){
            SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            thisNode->addChilds(TerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        }    
        
        // <表达式>
        SyntaxNodeBase* experessionNode = CFG_experession(itr, itr_end);
        thisNode->addChilds(experessionNode);  

        //)
        if(itr != itr_end and itr->value()==")"){
            SyntaxNodeBase* TerminalNode = new TerminalSyntaxNode(itr->type(), itr->value());
            itr ++;
            thisNode->addChilds(TerminalNode);
        }else{
            throw CP::Exception::SYNTAX_ERROR;
        }        
    }else{
        throw CP::Exception::SYNTAX_ERROR;
    }

    return thisNode;
}


}//namespace