#include <cstdio>
int main(){
    unsigned long long x,n,go;
    scanf("%llu %llu",&x,&n);
    go=(n/7)*5*250,n%=7;
    for(int i=0;i<n;i++){
        (i+x)%7==6||(i+x)%7==0?0:go+=250;
    }
    printf("%llu",go);
}