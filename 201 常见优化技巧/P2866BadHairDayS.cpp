#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 80000+30;
int n;
int info[MAX_N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
    }
    stack<pair<int, int>> stk;// <val, idx>;
    stk.push({0x3f3f3f3f, n+1});
    long long ans = 0;
    for(int i = n; i > 0; --i){
        while(info[i] > stk.top().first){
            stk.pop();
        }
        ans += stk.top().second - i - 1;
        stk.push({info[i], i});
    }
    cout << ans;
    return 0;
}