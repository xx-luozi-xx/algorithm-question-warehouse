#include <iostream>
using namespace std;
const int MAX_SIZE = 2e4 *2 +30;
//const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);

int n, m;

struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];

inline void eage_add(int a, int b){
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size ++;
}

int vit[MAX_SIZE];
void dfs(int now){
    vit[now] = 1;
    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        if(vit[eage[itr].b] == 0){
            //printf("[%d->%d]", now, eage[itr].b);
            dfs(eage[itr].b);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        eage_add(a, b);
    }
    dfs(1);
    cout << (vit[n]?"Yes":"No");
    return 0;
}