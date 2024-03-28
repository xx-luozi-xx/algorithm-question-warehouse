#include <stdio.h>
int a[10000],box,min,n,m,i;
int main(){
    for(scanf("%d %d",&n, &m);i<m;scanf("%d",&a[i]),box+=a[i],i++);
    for(min=box;i<n;scanf("%d",&a[i]),box+=a[i]-a[i-m],min>box?min=box:0,i++);
    return 0*printf("%d",min);
}