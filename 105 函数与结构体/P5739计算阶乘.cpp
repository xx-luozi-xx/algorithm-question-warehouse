#include <stdio.h>
int main(){
    unsigned long long ans = 1;
    int n; scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        ans*=i;
    }
    return 0*printf("%llu",ans);
}