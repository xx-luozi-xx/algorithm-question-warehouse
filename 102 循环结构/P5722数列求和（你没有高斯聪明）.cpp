#include <stdio.h>
int xxd(int n){
    if(n==1)return 1;
    return n+xxd(n-1);
}
int main(){
    int n;scanf("%d",&n);
    printf("%d",xxd(n));
}