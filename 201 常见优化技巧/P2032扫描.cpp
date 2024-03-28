#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e6+30;

int n, k;

int info[MAX_N];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
    }
    deque<pair<int, int>> que; // <vla, idx>
    for(int i = 1; i <= n; ++i){
        if(que.front().second <= i-k){
            que.pop_front();
        }
        while(!que.empty() and info[i] >= que.back().first){
            que.pop_back();
        }
        que.push_back({info[i], i});
        if(i >= k)
            cout << que.front().first << '\n';
    }
    return 0;
}