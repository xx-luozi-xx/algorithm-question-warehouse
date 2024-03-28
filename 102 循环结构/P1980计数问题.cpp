#include<stdio.h>
int main(){
    int n,x,i,ans=0;scanf("%d %d",&n,&x);
    for(i=1;i<=n;i++){
        int j=i;
        while(j){
            j%10==x?ans++:0;
            j/=10;
        }
    } 
    printf("%d",ans);   
}