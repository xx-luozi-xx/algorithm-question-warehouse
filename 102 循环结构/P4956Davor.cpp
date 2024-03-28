#include <stdio.h>
int main(){
    int a; scanf("%d",&a);
    a/=52*7;
    for(int k=1;1;k++)
        if(a-3*k<=100)
            return 0*printf("%d\n%d",a-3*k,k);
}