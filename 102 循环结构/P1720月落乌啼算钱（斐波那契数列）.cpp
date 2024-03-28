#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    unsigned long long a[233]={0,1,1};
    for(int i = 3; i<50;i++){
        a[i] = a[i-1]+a[i-2];
    }
    printf("%llu.00",a[n]);
}