//后缀表达式（逆波兰式）
// https://www.matiji.net/exam/dohomework/6332/2


#include <string>
#include <iostream>

#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;


int main(){
    string sin; cin >> sin;
    string hou;
    string stk;

    for(char c : sin){
        if(isdigit(c)){
            hou.push_back(c);
        }else{
            if(stk.empty() || stk.back() == '(' || c == '('){
                stk.push_back(c);
            }else if(c == ')'){
                while(stk.back() != '('){
                    hou.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();//pop '('
            }else if(c == '+' || c == '-'){
                while(!(stk.empty() || stk.back() == '(')){
                    hou.push_back(stk.back());
                    stk.pop_back();
                }
                stk.push_back(c);
            }else if(c == '*' || c == '/'){
                while(!(stk.empty() || stk.back() == '(' || stk.back() == '+' || stk.back() == '-')){
                    hou.push_back(stk.back());
                    stk.pop_back();
                }
                stk.push_back(c);
            }else {
                assert(0);
            }
        }
    }
    while(!stk.empty()){
        hou.push_back(stk.back());
        stk.pop_back();
    }

    vector<int> vec;
    for(int i = 0; i < hou.size(); ++i){
        int need_out = (i==0);
        if(isdigit(hou[i])){
            vec.push_back(hou[i]-'0');
        }else{
            need_out = 1;
            int b = vec.back(); vec.pop_back();
            int a = vec.back(); vec.pop_back();
            int c;
            if(hou[i] == '+'){
                c = a + b;
            }else if(hou[i] == '-'){
                c = a - b;
            }else if(hou[i] == '*'){
                c = a * b;
            }else if(hou[i] == '/'){
                c = a / b;
            }else{
                assert(0);
            }
            vec.push_back(c);
        }
        //out put
        if(need_out){
            for(int num: vec){
                cout << num << ' ';
            }
            for(int j = i+1; j < hou.size(); ++ j){
                cout << hou[j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}