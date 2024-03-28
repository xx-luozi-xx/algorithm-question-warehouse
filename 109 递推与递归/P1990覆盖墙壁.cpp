#include <stdio.h>
#define MAX_SIZE (1000000+5)
#define mod 10000
int F[MAX_SIZE]{0,1,2};
int S[MAX_SIZE]{0,2,4};

int main(){
    int n;scanf("%d", &n);
    for(int i = 3; i <= n; ++i){
        F[i] = F[i-1]+F[i-2]+S[i-2]; F[i]%=mod;
        S[i] = 2*F[i-1]+S[i-1]; S[i]%=mod;
    }
    printf("%d", F[n]);
    return 0;
}
