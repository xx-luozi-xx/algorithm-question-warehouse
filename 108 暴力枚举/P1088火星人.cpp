#define STL  


#ifdef STL
#include <stdio.h>
#include <algorithm>
using namespace std;

int data[10010];
int N, M;

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", data+i);
    }
    for(int i = 0; i < M; ++i){
        next_permutation(data, data+N);
    }
    for(int i = 0; i < N; ++i){
        printf("%d ", data[i]);
    }
    return 0;
}


#endif

#ifndef STL
#include <stdio.h>

int data[10010]{};
bool looked[10010]{};
int N, M;

int times = 0;
int init;

int out[10010]{};
int out_size = 0;

void dfs(int k){
    if(k == 0){
        if(++times==M+1){
            for(int i = 0; i < out_size; ++i){
                printf("%d ", out[i]);
            }
            throw 0;
        }
    }

    for(int i = 0; i < N; ++i){
        if(init != 0){
            if(out[N-init] != data[i]){
                continue;
            }else{
                init--;
            }
        }
        if(looked[i] == false){
            looked[i] = true;
            out[out_size++] = data[i];
            dfs(k-1);
            out_size--;
            looked[i] = false;
        }
    }

}


int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        data[i] = i + 1;
    }    
    for(int i = 0; i < N; ++i){
        scanf("%d", &out[i]);
    }
    out_size = 0;
    init = N;

    try{
        dfs(N);
    }
    catch(...){
        return 0;
    }

}
#endif
