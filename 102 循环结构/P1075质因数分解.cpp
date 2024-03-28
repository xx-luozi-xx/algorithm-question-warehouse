#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    if(!(n%2)) return 0*printf("%d",n/2);
    for(int i = 3;i < n; i+=2)
        if(!(n%i)) return 0*printf("%d",n/i);
}