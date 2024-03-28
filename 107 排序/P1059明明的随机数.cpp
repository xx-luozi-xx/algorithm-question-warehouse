#include <stdio.h>
#include <algorithm>

int main(){
    int n;scanf("%d",&n);
    int *a = new int[n]{};
    bool *b = new bool[n]{};
    for(int i = 0; i< n; ++i){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    int cnt = n;
    for(int i = 1; i<n; ++i){
        a[i]==a[i-1]?--cnt,b[i] = 1:0;
    }
    printf("%d\n",cnt);
    for(int i = 0; i<n; ++i){
        b[i]?0:printf("%d ",a[i]);
    }

    delete[] a,b;
    return 0;
}