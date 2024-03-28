#include <stdio.h>
int main(){
    int ans=0, n, a[200]={0}; scanf("%d",&n);
    for(int i=0;i<n;scanf("%d",&a[i++]));
    for(int i=0;i<n;i++){
        for(int j=0;j<i;a[j]<a[i]?ans++:0,j++);
        printf("%d ",ans),ans=0;
    }
    return 0;
}