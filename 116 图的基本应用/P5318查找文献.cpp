#include <set>
#include <queue>
#include <bitset>
#include <iostream>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;

int n, m;
set<int> eage[MAX_N];

inline void eage_add(int a, int b)noexcept{
    eage[a].insert(b);
}

bitset<MAX_N> vit;
void dfs(int now)noexcept{
    if(vit[now]) return;

    cout << now << ' ';
    vit[now] = 1;
    for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
        dfs(*itr);
    }
}
void bfs()noexcept{
    vit = bitset<MAX_N>();
    queue<int> que;
    que.push(1);

    while(!que.empty()){
        int now = que.front();
        que.pop();
        if(vit[now]) continue;

        cout << now << ' ';
        vit[now] = 1;

        for(auto itr = eage[now].begin(); itr != eage[now].end(); ++itr){
            que.push(*itr);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        eage_add(a, b);
    }

    dfs(1);
    cout << '\n';
    bfs();
    return 0;
}
