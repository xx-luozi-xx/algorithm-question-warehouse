#include <stdio.h>
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a,b;
        char x[233];
        scanf("%s %d %d",x,&a,&b);
        a+b>140&&0.7*a+0.3*b>=80?printf("Excellent\n"):printf("Not excellent\n");
    }
    return 0;
}