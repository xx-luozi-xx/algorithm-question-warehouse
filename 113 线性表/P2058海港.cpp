#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;

queue<pair<int, int>> que; //<time, guo>
int guo[MAX_N];
int guo_cnt = 0;

inline void add(int t, int x)noexcept{
    que.push({t, x});
    if(guo[x] == 0){
        guo_cnt++;
    }
    guo[x]++;
}
inline void pop(int t) noexcept{
    t = t - 86400;
    while(!que.empty() && que.front().first <= t){
        if(--guo[que.front().second] == 0){
            guo_cnt --;
        }
        que.pop();
    }
}
int main(){
    int n; cin >> n;
    for(int _ = 0; _ < n;++_){
        int t, k; cin >> t >> k;
        for(int _ = 0; _ < k; ++_){
            int x; cin >> x;
            add(t, x);
        }
        pop(t);
        cout << guo_cnt << '\n';
    }
    return 0;
}