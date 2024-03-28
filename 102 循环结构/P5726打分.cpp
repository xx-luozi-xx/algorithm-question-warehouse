#include <stdio.h>
int swap(int &a, int &b ){
    return a=a^b,b=a^b,a=a^b;
}
int main(){
    int all=0, n, a[2000] = {0}; scanf("%d",&n);
    for(int i=0; i<n; scanf("%d",&a[i]),i++);
    for(int i=0; i<n-1;a[i]<a[i+1]?swap(a[i],a[i+1]):0,i++);
    for(int i=0; i<n-1;a[i]>a[i+1]?swap(a[i],a[i+1]):0,i++);
    for(int i=0; i<n-2; all+=a[i],i++);
    return 0*printf("%.2lf",double(all)/(n-2));
}