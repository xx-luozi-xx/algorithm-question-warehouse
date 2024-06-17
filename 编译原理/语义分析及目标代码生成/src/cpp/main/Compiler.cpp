#include "setting.h"
#include "CP_Exception.h"

#include "lexical.h"
#include "syntaxTree.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    using namespace CP;
    try{
        ifstream fin("./data/program.txt");
        if(fin.is_open() == false){
            std::cerr << "fin err";
            // return -1;
        }

        Artical artical(cin);

        //lexical analysis
        list<Word> words;
        while(!artical.read_end()){
            Word word = artical.read_word();
            word.format();
            words.push_back(word);
        }

        //Syntax Analysis
        SyntaxTree syntaxTree(words);

        ofstream fout("program.code");
        syntaxTree.getObjectCode(fout);

    }catch(CP::Exception exception){
        std::cerr << (int)exception;
        return -1;
    }
    return 0;
}

