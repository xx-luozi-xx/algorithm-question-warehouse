#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000;
int n;
char data[MAX_N];
vector<bool> yes;

stack<int> stk;

int main(){
    cin >> data;
    n = strlen(data);
    yes = vector<bool>(n, false);

    for(int i = 0; i < n; ++i){
        if(data[i] == ']' || data[i] == ')'){
            int find = -1;
            if(!stk.empty()){
                find = stk.top();
            }
            if(find != -1){
                if((data[i] == ']' && data[find] == '[' || data[i] == ')' && data[find] == '(')){
                    yes[i] = 1;
                    yes[find] = 1;
                    stk.pop();
                }
            }
            
        }else{
            stk.push(i);
        }
    }
    for(int i = 0; i < n; ++i){
        if(yes[i]){
            cout << data[i];
        }else{
            if(data[i] == '(' || data[i] == ')'){
                cout << "()";
            }else{
                cout << "[]";
            }
        }
    }
    return 0;
}