#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1010;
const int MAX_M = MAX_N*MAX_N;

int n, m;

struct Eage{
    int b;
    int next;
}eage[MAX_M];
int eage_size = 1;
int head[MAX_N];
int d_in[MAX_N];
int eage_hav[MAX_M];
inline void eage_add(int a, int b)noexcept{
    if(eage_hav[a*1001+b] == 0){
        eage[eage_size].b = b;
        eage[eage_size].next = head[a];
        head[a] = eage_size ++;
        d_in[b] ++;
        eage_hav[a*1001+b] = 1;
    }
}

int tmp[MAX_N];
int hav[MAX_N], hav_size;

int topu_size = 0;
int topu_get[MAX_N];
int next_topu[MAX_N], next_topu_size;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int K; cin >> K;
        memset(tmp, 0, sizeof(tmp));
        hav_size = 0;
        for(int k = 1; k <= K; ++k){
            int a; cin >> a;
            tmp[a] = 1;
            hav[hav_size++] = a;
        }

        for(int j = 0; j < hav_size; ++j){
            for(int k = hav[0]; k <= hav[hav_size-1]; ++k){
                if(tmp[k] == 0){
                    eage_add(hav[j], k);
                }
            }
        }
    }


    int topu_round = 0;
    while(topu_size < n and topu_round < n){
        topu_round ++;
        next_topu_size = 0;
        for(int i = 1; i <= n; ++i){
            if(d_in[i] == 0 and !topu_get[i]){
                topu_size ++;
                next_topu[next_topu_size++] = i;
                topu_get[i] = 1;
            }
        }
        for(int i = 0; i < next_topu_size; ++i){
            for(int itr = head[next_topu[i]]; itr != 0; itr = eage[itr].next){
                d_in[eage[itr].b]--;
            }
        }
    }
    cout << topu_round;
    return 0;
}

