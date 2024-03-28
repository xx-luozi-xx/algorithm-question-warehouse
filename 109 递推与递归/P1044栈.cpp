#include <stdio.h>

int count[25]{1,1};
int n = 0;

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            count[i] += count[(i-1)-j]*count[j];
        }
    }

    // for(int i = 0; i < 20; ++i){
    //     printf("%d %d\n", i, count[i]);
    // }

    printf("%d", count[n]);
    return 0;
}