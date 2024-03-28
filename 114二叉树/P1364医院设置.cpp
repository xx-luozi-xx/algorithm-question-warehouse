#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_SIZE = 1000;
int n;
struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
int w[MAX_SIZE];
inline void add(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}

int vit[MAX_SIZE];
int dfs_ans;
void dfs(int now, int deep)noexcept{
    if(!vit[now]){
        vit[now] = 1;
        dfs_ans += deep * w[now];
        for(int itr = head[now]; itr != 0; itr = eage[itr].next){
            if(!vit[eage[itr].b]){
                dfs(eage[itr].b, deep+1);
            }
        }
    }
}

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int w_, b1, b2;
        cin >> w_ >> b1 >> b2;
        w[i] = w_;
        if(b1){
            add(i, b1);
            add(b1, i);
        }
        if(b2){
            add(i, b2);
            add(b2, i);
        }
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= n ;++i){
        memset(vit, 0, sizeof(vit));
        dfs_ans = 0;
        dfs(i, 0);
        ans = min(ans, dfs_ans);
    }
    cout << ans;
    return 0;
}