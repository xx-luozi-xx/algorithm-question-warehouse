#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e4+30;

int n;

pair<int, int> info[MAX_N];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> info[i].first >> info[i].second;
    }
    sort(info, info+n);
    stack<pair<int, int>> stk;
    stk.push(info[0]);
    for(int i = 1; i < n; ++i) {
        if(info[i].first > stk.top().second){
            stk.push(info[i]);
        }else{
            stk.top().second = max(info[i].second, stk.top().second);
        }
    }
    long long ans = 0;
    while(!stk.empty()){
        ans += stk.top().second - stk.top().first;
        stk.pop();
    }
    cout << ans;
    return 0;
}