#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000;
int n;
int src, dsc;
struct Eage{
    int b;
    int w;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
inline void add_eage(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}
int fa[MAX_SIZE];

int deep_cnt[MAX_SIZE];
void make_fa_and_deep_cnt(int now, int deep, int father)noexcept{
    deep_cnt[deep]++;
    fa[now] = father;

    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        if(eage[itr].b != father){
            eage[itr].w = 1;
            make_fa_and_deep_cnt(eage[itr].b, deep+1, now);
        }else{
            eage[itr].w = 2;
        }
    }
}

int vit[MAX_SIZE];
int bfs()noexcept{
    queue<pair<int, int>> que;// <dst, idx>
    que.push({0, src});
    while(!que.empty()){
        int dst = que.front().first;
        int now = que.front().second;
        que.pop();

        if(vit[now]){
            continue;
        }
        vit[now] = 1;

        if(now == dsc){
            return dst;
        }

        for(int itr = head[now]; itr != 0; itr = eage[itr].next){
            que.push({dst+eage[itr].w, eage[itr].b});
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n-1; ++i){
        int a, b;
        cin >> a >> b;
        add_eage(a, b);
        add_eage(b, a);
    }
    cin >> src >> dsc;

    make_fa_and_deep_cnt(1, 1, -1);
    int W = 0;
    int D = 0;
    for(int i = 1; i < MAX_SIZE; ++i){
        W = max(W, deep_cnt[i]);
        if(deep_cnt[i]){
            D = i;
        }
    }

    int dst = bfs();
    cout << D << '\n'
         << W << '\n'
         << dst;
         return 0;
}