#include <iostream>
#include <list>
#include <string>
#include <set>
using namespace std;



class Word{
public:
    enum Buffer_type{
        BF_NUMBER, BF_STRING, BF_SYMBOL, 
    };

    enum Type{
       KEYWORDS, IDENTIFIER, NUMBER, OPERATOR, SEPARATOR, 
    };

public:
    static set<string> keywords_set;
    static set<string> operator_set;
    static set<string> separator_set;

    static set<string> operator_alpha_set;
    static set<string> separator_alpha_set;
    static set<string> alphabet_alpha_set;
    static set<string> number_alpha_set;

public:

    string      data;
    Buffer_type buffer_type;
    Type        type;
    size_t      location;
};

int main(){
    cout << "x";
}




set<string> Word::keywords_set = {
    "CONST", 
    "VAR", 
    "PROCEDURE", 
    "BEGIN", 
    "END", 
    "ODD", 
    "IF", 
    "THEN", 
    "CALL", 
    "WHILE", 
    "DO", 
    "READ", 
    "WRITE", 
};

set<string> Word::operator_set = {
    "=", 
    ":=", 
    "+", 
    "-", 
    "*", 
    "/", 
    "#", 
    "<", 
    "<=", 
    ">", 
    ">=", 
};

set<string> Word::separator_set = {
    ";", 
    ",", 
    ".", 
    "(", 
    ")", 
};

set<string> Word::operator_alpha_set;
set<string> Word::separator_alpha_set;
set<string> Word::alphabet_alpha_set;
set<string> Word::number_alpha_set;