#include <stdio.h>
int main(){
    int n; scanf("%d", &n);
    int ans = 0;
    while(n--){
        int in; scanf("%d", &in);
        ans ^= in;
    }
    printf("%d", ans);
    return 0;
}