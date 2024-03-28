#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> stk;
    while(1){
        if(isdigit(cin.peek())){
            int num = 0;
            while(cin.peek() != '.'){
                char in; cin >> in;
                num*=10; num += in-'0';
            }{char in; cin >> in;}
            stk.push(num);
        }else if(cin.peek() == '@'){
            break;
        }else{
            char op; cin >> op;
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            if(op == '+'){
                stk.push(a+b);
            }else if(op == '-'){
                stk.push(b-a);
            }else if(op == '*'){
                stk.push(a*b);
            }else if(op == '/'){
                stk.push(b/a);
            }else{
                throw "x";
            }
        }
    }
    cout << stk.top();
    return 0;
}