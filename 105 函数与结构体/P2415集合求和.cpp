#include <stdio.h>
#include <cmath>
int main(){
    int ans=0,sum = 0,box;
    while(scanf("%d",&box)!=EOF){
        sum+=box,ans++;
    }
    return 0*printf("%llu",(unsigned long long)(sum*(long long)pow(2,ans-1)));
}