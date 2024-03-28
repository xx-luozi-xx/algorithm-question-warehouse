#include <bits/stdc++.h>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1500+30;
const int MAX_M = 5e4+30;

int n, m;

vector<pair<int, int>> eage[MAX_N]; //<point, w>
vector<pair<int, int>> reage[MAX_N]; //<point, w>

bool can_go[MAX_N];
void make_can_go(int now)noexcept{
    if(can_go[now]) return;
    can_go[now] = 1;
    for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
        make_can_go(itr->first);
    }
}

bool solved[MAX_N];
int len[MAX_N];
int get_len(int now)noexcept{
    if(solved[now]) return len[now];
    for(auto itr = reage[now].begin(); itr != reage[now].end(); ++itr){
        if(can_go[itr->first]){
            len[now] = max(get_len(itr->first)+itr->second, len[now]);
        }
    }
    solved[now] = 1;
    return len[now];
}

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, w; cin >> a >> b >> w;
        eage[a].push_back({b, w});
        reage[b].push_back({a, w});
    }
    make_can_go(1);
    if(can_go[n] == 0){
        cout << "-1";
    }else{
        solved[1] = 1;
        cout << get_len(n);
    }
    return 0;
}

