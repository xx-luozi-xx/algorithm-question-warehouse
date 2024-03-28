#include <iostream>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;
const int MAX_M = 1e5+30;

int n, m;

struct Eage{
    int b;
    int next;
}eage[MAX_M];
int eage_size = 1;
int head[MAX_N];

inline void eage_add(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}

int ans[MAX_N];
void dfs(int now, int val)noexcept{
    if(ans[now]) return;

    ans[now] = val;
    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        dfs(eage[itr].b, val);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        eage_add(b, a);
    }
    for(int i = n; i > 0; --i){
        dfs(i, i);
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}