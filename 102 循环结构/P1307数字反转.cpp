#include <stdio.h>
#include <math.h>
int main(){
    int a; scanf("%d",&a);
    if(!a){
        printf("%d",0);
        return 0;
    }
    int sgn = a > 0? 1 : -1;
    a = abs(a);
    int re = 0, n = log10(a);
    for(int i = 0; n >= 0; i++,n--){
        re += (a / (int)pow(10,i)) % 10 * (int)pow(10,n);
    }
    printf("%d",re*sgn);
}