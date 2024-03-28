#include <stdio.h>
int main(){
    int n,k,A=0,B=0,na=0,nb=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        i%k?(A+=i,na++):(B+=i,nb++);
    }printf("%.1lf %.1lf",double(B)/nb,double(A)/na);
}