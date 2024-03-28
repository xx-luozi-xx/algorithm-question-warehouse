#include <stdio.h>
#include <math.h>
#define MAX_SIZE 1005

unsigned long long f[MAX_SIZE]{0,1};
unsigned long long F[MAX_SIZE]{0,1};

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        f[i] = 1 + F[i/2];
        F[i] = F[i-1] + f[i];
        //printf("%d %d %d\n", i, f[i], F[i]);
    }

    printf("%d", f[n]);
}