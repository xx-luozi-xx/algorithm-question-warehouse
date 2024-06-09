#pragma once

#include <list>
#include <string>
#include <set>

#include <assert.h>


using namespace std;

namespace CP{

class Artical;
class Word;

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
    
    Type type() const;
    string value() const;

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