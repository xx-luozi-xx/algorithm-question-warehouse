#include <stdio.h>
int main(){
    double s=0;int k,i;scanf("%d",&k);
    for(i=1;s+1.0/i<=k;i++){
        s+=1.0/i;
    }
    printf("%d",i);
}