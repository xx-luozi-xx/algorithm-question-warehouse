#include <iostream>
#include <list>
#include <string>
#include <set>

#include <assert.h>
using namespace std;

#define DEBUG_
#define LOCAL_


namespace CP{

class Artical;
class Word;

enum Exception{
    LEXICAL_ERROR,
};

class Artical{
public:
    Artical(istream& in);

    bool read_end()const;
    Word read_word();

protected:
    string data_;
    string::iterator read_ptr_;
};

class Word{
friend Artical;

public:
    enum Type{
        BF_NUMBER, BF_STRING, BF_SYMBOL, 
        KEYWORDS, IDENTIFIER, NUMBER, OPERATOR, SEPARATOR, 
        ERROR,
    };
    
public:
    void format();
    string print_info() const;
    
public:
    static set<string> keywords_set;
    static set<string> operator_set;
    static set<string> separator_set;

    static set<string> symbol_alpha_set;
    static set<string> alphabet_alpha_set;
    static set<string> number_alpha_set;
    static set<string> space_alpha_set;

    static bool is_usable_alpha(char c);
protected:

    string      data_;
    Type        buffer_type_;
    Type        type_;
    size_t      location_;
};

}//namespace 

int main(){
    using namespace CP;
    try{
        Artical artical(cin);
        list<Word> words;
        while(!artical.read_end()){
            Word word = artical.read_word();
            words.push_back(word);
        }
        for(Word& word: words){
                word.format();
        }
        for(Word& word: words){
            cout << word.print_info() << '\n';
        }
    }catch(CP::Exception){
        cout << "Lexical Error";
    }
    return 0;
}

namespace CP{

Artical::Artical(istream& in){
    char input;
    while(input=cin.get()
                #ifdef LOCAL
                    , input != '!'
                #else
                    , input != EOF
                #endif
                        ){
        if('a' <= input && input <= 'z'){
            input += (-'a'+'A');
        }
        data_.push_back(input);
    }

    read_ptr_ = data_.begin();
}

bool 
Artical::read_end()const{
    return read_ptr_ == data_.end(); 
}

Word
Artical::read_word(){
    //过滤空白符
    while(!read_end() && Word::space_alpha_set.count(string(1, *read_ptr_))){
        read_ptr_++;
    }
    if(!read_end() && !Word::is_usable_alpha(*read_ptr_)){
        throw Exception::LEXICAL_ERROR;
    }
#ifdef DEBUG
    cout << string("(")+(*read_ptr_)+")";
#endif
    Word word;
    word.location_ = read_ptr_-data_.begin();
    if(Word::symbol_alpha_set.count(string(1, *read_ptr_))){//符号
        word.buffer_type_ = Word::Type::BF_SYMBOL;
        word.data_.push_back(*(read_ptr_++));
        if(!read_end() && *read_ptr_ == '=' && 
            (word.data_ == "<" ||
            word.data_ == ">" ||
            word.data_ == ":")
        ){
#ifdef DEBUG
            printf("|=__%c__", *read_ptr_);
#endif         
            word.data_.push_back(*(read_ptr_++));
        }
    }else if(Word::alphabet_alpha_set.count(string(1, *read_ptr_))){//朴素词
        word.buffer_type_ = Word::Type::BF_STRING;
        while(!read_end() &&
        (   Word::number_alpha_set.count(string(1, *read_ptr_)) ||
            Word::alphabet_alpha_set.count(string(1, *read_ptr_))
        )){
#ifdef DEBUG
            printf("->%c", *read_ptr_);
#endif
            word.data_.push_back(*(read_ptr_++));
        }
    }else if(Word::number_alpha_set.count(string(1, *read_ptr_))){//数字
        word.buffer_type_ = Word::Type::BF_NUMBER;
        while(!read_end() && Word::number_alpha_set.count(string(1, *read_ptr_))){
            word.data_.push_back(*(read_ptr_++));
        }
        if(!read_end() && Word::alphabet_alpha_set.count(string(1, *read_ptr_))){
            throw Exception::LEXICAL_ERROR;     
        }
    }else{
#ifdef DEBUG
        printf("{%c}", *read_ptr_);
#endif
        assert(0);
    }

    //过滤空白符
    while(!read_end() && Word::space_alpha_set.count(string(1, *read_ptr_))){
        read_ptr_++;
    }
    if(word.data_.size() > 10){
        throw Exception::LEXICAL_ERROR;
    }
#ifdef DEBUG
    cout << "["+word.data_+"]";
#endif
    return word;
}

bool 
Word::is_usable_alpha(char c){
    string str(1, c);
    return 
        symbol_alpha_set.count(str)||
        alphabet_alpha_set.count(str)||
        number_alpha_set.count(str)
    ;
}

void 
Word::format(){
    if(buffer_type_ == BF_SYMBOL){
        if(operator_set.count(data_)){
            type_ = OPERATOR;
        }else if(separator_set.count(data_)){
            type_ = SEPARATOR;
        }else{
            throw Exception::LEXICAL_ERROR;
            while(1);
            assert(0);
        }
    }else if(buffer_type_ == BF_NUMBER){
        type_ = NUMBER;
    }else if(buffer_type_ == BF_STRING){
        if(keywords_set.count(data_)){
            type_ = KEYWORDS;
        }else{
            type_ = IDENTIFIER;
        }
    }else{
        assert(0);
    }
}

string
Word::print_info()const{
    switch (type_)
    {
    case KEYWORDS:
        return data_;
    case IDENTIFIER:
        return "IDENTIFIER "+data_;
    case NUMBER:
        return "NUMBER "+to_string(stoi(data_));
    case OPERATOR:
        return data_;
    case SEPARATOR:
        return data_;
    default:
        assert(0);     
    }
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

set<string> Word::symbol_alpha_set = {
    ";", 
    ",", 
    ".", 
    "(", 
    ")", 
    "=", 
    ":", 
    "+", 
    "-", 
    "*", 
    "/", 
    "#", 
    "<", 
    ">", 
};
set<string> Word::alphabet_alpha_set = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "N",
    "M",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
};
set<string> Word::number_alpha_set = {
    "1", 
    "2", 
    "3", 
    "4", 
    "5", 
    "6", 
    "7", 
    "8", 
    "9", 
    "0",  
};


set<string> Word::space_alpha_set = {
    " ",
    "\n",
    "\t",
#ifdef LOCAL
    "!",
#endif
};







}//namespace