#include <stdio.h>
int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int last = 0;
    int now;
    unsigned long long cnt = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &now);
        now>x?cnt+=now-x, now = x:0;
        now+last>x?cnt+=now+last-x, now-=(now+last-x):0;

        last = now;
    }
    printf("%llu", cnt);
    return 0;
}