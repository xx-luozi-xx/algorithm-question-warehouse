#include <cstdio>
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",!(a%4)&&a%100||!(a%400));//是4的倍数但不是100的倍数，或者是400的倍数。
}