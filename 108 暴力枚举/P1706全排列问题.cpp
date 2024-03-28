#include <stdio.h>

int data[30];
bool looked[30]{};
int n;

int out[30];
int out_size = 0;

void dfs(int k){
    if(k == 0){
        for(int i = 0; i < out_size; ++i){
            printf("%5.d", out[i]);
        }printf("\n");
    }

    for(int i = 0; i < n; ++i){
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
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        data[i] = i+1;
    }

    dfs(n);

    return 0;
}


