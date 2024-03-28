#include <stdio.h>
int main(){
    int a,n=1;
    scanf("%d",&a);
    while(a>1?a/=2,n++:0);
    printf("%d",n);
}