#include <stdio.h>

int data[30];
bool looked[30]{};
int n,k;

int out[30];
int out_size = 0;

void dfs(int k, int last){
    if(k == 0){
        for(int i = 0; i < out_size; ++i){
            printf("%3.d", out[i]);
        }
        printf("\n");
    }

    for(int i = last; i < n; ++i){
        if(looked[i] == false){
            looked[i] = true;
            out[out_size++] = data[i];
            dfs(k-1, i + 1);
            out_size--;
            looked[i] = false;
        }
    }

}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < 30; ++i){
        data[i] = i+1;
    }

    dfs(k, 0);
}
