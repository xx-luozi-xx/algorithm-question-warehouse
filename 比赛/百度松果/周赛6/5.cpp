//表达式求值
// https://www.matiji.net/exam/dohomework/6332/5

#include <list>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

#define printf nothing
void nothing(...){}

int main(){
    list<string> lst;
    string sin;
    while(cin >> sin){
        lst.push_back(sin);
    }

    //not
    for(auto itr = lst.begin(); itr != lst.end(); ++itr){
        if(*itr == "not"){
            auto itr2 = itr;
            itr2++;
            if(itr2 == lst.end()){
                //err
                cout << "error"; printf("1");
                return 0;
            }else if(*itr2 == "not"){
            }else if(*itr2 == "true"){
            }else if(*itr2 == "false"){
            }else{
                cout << "error";printf("2");
                return 0;
            }
        }
    }

    for(auto itr = lst.begin(); itr != lst.end(); ++itr){
        if(*itr == "not"){
            auto itr2 = itr;
            itr2++;
            if(*itr2 == "not"){
                lst.erase(itr2);
            }else if(*itr2 == "true"){
                *itr2 = "false";
            }else if(*itr2 == "false"){
                *itr2 = "true";
            }

            itr = lst.erase(itr);
            itr--;
        }
    }
    //and
    for(auto itr = lst.begin(); itr != lst.end(); ++itr){
        if(*itr == "and"){
            if(itr == lst.begin()){
                cout << "error";printf("3");
                return 0;
            }
            auto itr1 = itr;
            auto itr2 = itr;
            itr1--;
            itr2++;
            if(itr2 == lst.end() || !(*itr1 == "true" || *itr1 == "false") || !(*itr2 == "true" || *itr2 == "false") ){
                cout << "error";printf("4");
                return 0;
            }
            string val;
            if(*itr1 == *itr2){
                val = *itr1;
            }else{
                val = "false";
            }
            lst.erase(itr1);
            lst.erase(itr);
            *itr2 = val;
            itr = itr2;
        }
    }
    //or
    for(auto itr = lst.begin(); itr != lst.end(); ++itr){
        if(*itr == "or"){
            if(itr == lst.begin()){
                cout << "error";printf("5");
                return 0;
            }
            auto itr1 = itr;
            auto itr2 = itr;
            itr1--;
            itr2++;
            if(itr2 == lst.end() || !(*itr1 == "true" || *itr1 == "false") || !(*itr2 == "true" || *itr2 == "false") ){
                cout << "error";printf("6");
                return 0;
            }
            string val;
            if(*itr1 == *itr2){
                val = *itr1;
            }else{
                val = "true";
            }
            lst.erase(itr1);
            lst.erase(itr);
            *itr2 = val;
            itr = itr2;
        }
    }
    if(lst.size() != 1){
        cout << "error";printf("7");
        return 0;  
    }
    cout << lst.back();
    return 0;
}