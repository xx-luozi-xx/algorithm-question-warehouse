#include <stdio.h>
int main(){
    int p,day=1,gold[100000],n;scanf("%d",&n);
    for(int i=1;i<=n;0){
        for(p=day;p>0;p--){
            gold[i++]=day;
        }
        day++;
    }
    unsigned long long all=0;
    for(int i=1;i<=n;i++){
        all+=gold[i];
    }
    printf("%llu",all);
}