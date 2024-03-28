#include <stdio.h>

int main(){
    long long a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=", a, b, p);
    long long out = 1;
    while(b!=0){
        if(b&1){//奇数
            out*=a, out%=p;
            --b;
        }else{
            a*=a, a%=p;
            b/=2;
        }
    }
    printf("%lld", out);
}