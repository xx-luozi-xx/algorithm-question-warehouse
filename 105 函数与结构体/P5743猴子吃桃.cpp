#include <stdio.h>
int main(){
    int a;scanf("%d",&a);
    int dp = 1;
    while(--a){
        dp=2*(dp+1);
    }
    return 0*printf("%d",dp);
}