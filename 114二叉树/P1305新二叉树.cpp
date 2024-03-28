#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 200;

struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
inline void add_eage(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}

void dfs(int now)noexcept{
    cout << char(now);
    vector<int> go;
    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        go.push_back(eage[itr].b);
    }
    for(int i = go.size()-1; i >= 0; --i){
        dfs(go[i]);
    }
}

int main(){
    int n; cin >> n;
    int root;
    for(int i = 1; i <= n; ++i){
        string in; cin >> in;
        if(i == 1){
            root = in[0];
        }
        if(in[1] != '*'){
            add_eage(in[0], in[1]);
        }
        if(in[2] != '*'){
            add_eage(in[0], in[2]);
        }
    }
    dfs(root);
    return 0;
}

