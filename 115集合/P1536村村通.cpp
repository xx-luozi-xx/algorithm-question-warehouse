#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = (10000+30)<<1;

struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
inline void add_eage(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size ++;
}

int vit[MAX_SIZE];
void dfs(int now)noexcept{
    if(vit[now]) return;
    vit[now] = 1;
    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        if(!vit[eage[itr].b])
            dfs(eage[itr].b);
    }
}

inline void eage_init()noexcept{
    eage_size = 1;
    memset(eage, 0, sizeof(eage));
    memset(head, 0, sizeof(head));
    memset(vit, 0, sizeof(vit));
}

int main(){
    while(1){
        eage_init();
        int n, m;
        cin >> n; if(n == 0) return 0;
        cin >> m;

        while(m--){
            int a, b;
            cin >> a >> b;
            add_eage(a, b);
            add_eage(b, a);
        }

        int ans = -1;
        for(int i = 1; i <= n; ++i){
            if(!vit[i]){
                ans++;
                dfs(i);
            }
        }
        cout << ans << '\n';
    }    
}