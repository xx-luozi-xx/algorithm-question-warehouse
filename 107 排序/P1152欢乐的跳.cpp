#include <stdio.h>
#include <math.h>

int main(){
    int n; scanf("%d ",&n);
    int *a = new int[n]{};
    bool *b = new bool[n-1]{};
    for(int i = 0; i < n; scanf("%d",&a[i++]));
    for(int i = 0; i < n-1; ++i){
        int box = abs(a[i+1]-a[i]);
        if(1<=box&&box<=n-1&&!b[box]){
            b[box]=!b[box];
        }else{
            printf("Not jolly");
            return 0;
        }
    }
    printf("Jolly");
    return 0;
}