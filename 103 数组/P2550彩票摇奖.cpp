#include <stdio.h>
int s[10],a[10],n,prise[10],ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<7;scanf("%d",&s[i]),i++);
    while(n--){
        ans=0;
        for(int i=0;i<7;scanf("%d",&a[i]),i++);
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++){
                if(s[i]==a[j])
                    ans++;
            }
        prise[7-ans]+=1;
    }
    for(int i=0;i<7;printf("%d ",prise[i]),i++);
    return 0;
}