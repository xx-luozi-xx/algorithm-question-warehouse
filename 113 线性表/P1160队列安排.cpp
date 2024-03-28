#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;

int data[MAX_N], data_size = 1;
int nxt[MAX_N];
int pre[MAX_N];

int head[MAX_N];

int dead[MAX_N];

void add(int a, int b, int num){// a.nxt == b  
    head[num] = data_size;
    data[data_size] = num;

    nxt[data_size] = nxt[a]; 
    nxt[a] = data_size;

    pre[data_size] = pre[b];
    pre[b] = data_size;

    data_size++;
}

void init(){
    data[0] = 1;
    nxt[0] = 0;
    pre[0] = 0;
}

int first_ = 1;

int main(){
    init();
    int n; cin >> n;
    for(int i = 2; i <= n; ++i){
        int k, p;
        cin >> k >> p;
        if(p == 0){//左边
            int b = head[k];
            int a = pre[b];
            add(a, b, i);

            if(k == first_){
                first_ = i;
            }

        }else{
            int a = head[k];
            int b = nxt[a];
            add(a, b, i);
        }
    }
    int m; cin >> m;
    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        dead[x] = 1;
    }

    int first = 1;
    for(int itr = head[first_]; itr != head[first_] || first; itr = nxt[itr]){
        first = 0;
        if(!dead[data[itr]]){
            cout << data[itr] << ' ';
        }
    }
    return 0;
}