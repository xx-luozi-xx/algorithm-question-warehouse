#include <stdio.h>
int main(){
    int n, max = -1, min = 100000; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int box; scanf("%d",&box);
        box > max? max = box:0;
        box < min? min = box:0;
    }
    printf("%d",max - min);
}