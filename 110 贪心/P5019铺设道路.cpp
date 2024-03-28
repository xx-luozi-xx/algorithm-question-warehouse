#include <stdio.h>
#define MAX_SIZE 100010

int work[MAX_SIZE]{};

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", work+i);
    }
    unsigned long long cnt = 0;
    for(int i = 0; i < n; ++i){
        if(work[i]>work[i+1]){
            cnt+=work[i]-work[i+1];
        }
    }
    printf("%llu", cnt);
    return 0;
}