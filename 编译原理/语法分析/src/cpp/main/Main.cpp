#include "setting.h"
#include "CP_Exception.h"

#include "lexical.h"
#include "syntaxTree.h"

#include <iostream>
using namespace std;

int main(){
    using namespace CP;
    try{
        Artical artical(cin);

        //lexical analysis
        list<Word> words;
        while(!artical.read_end()){
            Word word = artical.read_word();
            words.push_back(word);
        }
        for(Word& word: words){
            word.format();
        }

        //Syntax Analysis
        SyntaxTree syntaxTree(words);
        syntaxTree.print_info();

    }catch(CP::Exception exception){
        switch (exception)
        {
        case LEXICAL_ERROR:
            cout << "Lexical Error";
            break;
        case SYNTAX_ERROR:
            cout << "Syntax Error";
            break;
        default:
            assert(0);
        }
    }
    return 0;
}

