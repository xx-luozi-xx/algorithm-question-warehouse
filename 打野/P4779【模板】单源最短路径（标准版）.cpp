#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6;
const int MAX_M = 1e6;
struct Graph{
    struct Eage{
        int b;
        int w;
        int next;
    }eage[MAX_M*2+30];
    int eage_size = 1;
    int head[MAX_N+30]{};
    void add(int a, int b, int w){
        eage[eage_size].b = b;
        eage[eage_size].w = w;
        eage[eage_size].next = head[a];
        head[a] = eage_size++;
    }
}G;

int dis[MAX_N]{};
int vis[MAX_N]{};

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        G.add(a, b, w);
    } 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;//<dis to s, idx>
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    que.emplace(pair<int, int>(0, s));
    dis[s] = 0;

    while(!que.empty()){
        int now = que.top().second;
        que.pop();
        if(vis[now]) continue;
        vis[now] = 1;
        for(int itr = G.head[now]; itr!=0; itr = G.eage[itr].next){
            if(dis[now]+G.eage[itr].w < dis[G.eage[itr].b]){
                dis[G.eage[itr].b] = dis[now]+G.eage[itr].w;
                que.emplace(pair<int, int>(dis[now]+G.eage[itr].w, G.eage[itr].b));
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        printf("%d ", dis[i]);
    }
    return 0;
}