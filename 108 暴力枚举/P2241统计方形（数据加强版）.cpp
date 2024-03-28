#include <stdio.h>
int main(){
    unsigned long long all = 0, sqr = 0;
    int n, m; scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            unsigned long long box = (n-i)*(m-j);
            i==j?sqr+=box:0;
            all+=box;       
        }
    }
    printf("%llu %llu",sqr, all-sqr);
    return 0;
}