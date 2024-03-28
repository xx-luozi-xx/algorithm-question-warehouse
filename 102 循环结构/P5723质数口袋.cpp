#include<stdio.h>
#include<cmath>
int xx(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)return 0;
    }
    return 1;
}
int main(){
    int bag=0,L,ans=0;scanf("%d",&L);
    for(int i=2;1;i++){
        if(xx(i)){
            if(bag+i<=L){
                bag+=i,ans++;
                printf("%d\n",i);
            }else{
                printf("%d",ans);
                return 0;
            }
        }
    }
}