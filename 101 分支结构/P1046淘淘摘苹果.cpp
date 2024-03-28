#include <cstdio>
int main(){
    int a[11],n=0;
    for(int i=0;i<11;i++)
        scanf("%d",&a[i]);
    a[10]+=30;
    for(int i=0;i<10;i++)
        a[i]<=a[10]?n++:0;
    printf("%d",n);
}