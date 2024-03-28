#include <stdio.h>
#include <string.h>

int main(){
    char str[50]{};
    unsigned long long N;
    scanf("%s", str);
    scanf("%llu", &N);
    int str_len = strlen(str);
    unsigned long long limit_up = str_len;
    for(limit_up = str_len; limit_up < N; limit_up*=2);

    while(N>str_len){
        while(limit_up/2>=N){
            limit_up/=2;
        }
        N = N - limit_up/2 - 1;
        N == 0? N = limit_up/2 : 0;
    }
    putchar(str[N-1]);
    return 0;
}

#ifdef MIRROR
//!我TM写了个镜像
#include <stdio.h>
#include <string.h>

int main(){
    char str[50]{};
    unsigned long long N;
    scanf("%s", str);
    scanf("%llu", &N);
    int str_len = strlen(str);
    unsigned long long limit_up = str_len;
    for(limit_up = str_len; limit_up < N; limit_up*=2);

    while(N>str_len){
        while(limit_up/2>=N){
            limit_up/=2;
        }
        N = limit_up + 1 - N;
    }
    putchar(str[N+1]);
    return 0;
}
#endif