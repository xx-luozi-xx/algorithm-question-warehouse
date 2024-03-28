#include <stdio.h>
int a[8848],i;
int main(){
    scanf("%d",&a[0]);
    if(a[0]==1) return 0*printf("1");
    for(i=1;a[i]=(a[i-1]&1?3*a[i-1]+1:a[i-1]/2),a[i]!=1;i++);
    for(;i>=0;printf("%d ",a[i--]));
    return 0;
}