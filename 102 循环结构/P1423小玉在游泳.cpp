#include <stdio.h>
#include <cmath>
int main(){
    double sn; scanf("%lf",&sn);
    printf("%d",int(ceil(log(1 - sn*0.01)/log(0.98))));
}