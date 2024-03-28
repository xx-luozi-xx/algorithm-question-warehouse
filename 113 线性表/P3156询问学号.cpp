#include <stdio.h>
#define MAX_SIZE (2000000+20)
int n, m;
int data[MAX_SIZE];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    while(m--){
        int x;
        scanf("%d", &x);
        printf("%d\n", data[x-1]);
    }
    return 0;
}