#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e3+30;

int k, n, m;

vector<int> eage[MAX_N];
inline void eage_add(int a, int b)noexcept{
    eage[a].push_back(b);
}

unordered_set<int> cow_pos;
unordered_set<int> vit_pos;
bitset<MAX_N> vit;

void dfs(int now)noexcept{
    if(vit[now]) return;
    vit[now] = 1;
    if(cow_pos.count(now)){
        vit_pos.insert(now);
    }

    for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
        dfs(*itr);
    }
}

inline bool judge(int now)noexcept{
    vit = bitset<MAX_N>();
    vit_pos = unordered_set<int>();
    dfs(now);
    return cow_pos == vit_pos;
}


int main(){
    cin >> k >> n >> m;
    for(int i = 1 ; i <= k; ++i){
        int in; cin >> in;
        cow_pos.insert(in);
    }

    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        eage_add(b, a);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += judge(i);
    }

    cout << ans;
    return 0;
}