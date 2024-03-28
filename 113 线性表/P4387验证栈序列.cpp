#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;
int in[MAX_N];
int out[MAX_N];

int main(){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        stack<int> stk;
        for(int i = 1; i <= n; ++i){
            cin >> in[i];
        }
        for(int i = 1; i <= n; ++i){
            cin >> out[i];
        }
        int p = 1;
        for(int i = 1; i <= n; ++i){
            stk.push(in[i]);
            while(!stk.empty() and p<=n and stk.top() == out[p]){
                stk.pop();
                ++p;
            }
        }
        if(stk.empty()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}