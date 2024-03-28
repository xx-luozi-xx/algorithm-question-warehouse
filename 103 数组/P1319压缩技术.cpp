#include <stdio.h>
int main(){
    int n,a=0,l=0,ans=1; scanf("%d",&n);
    l=n;
    for(int i = 0; i<n*n; i++){
        if(!a){
            scanf("%d",&a);
            ans++,ans%=2;
            if(!a){//开局判0
                i--;
                continue;
            }
        }
        printf("%d",ans),l--,a--;
        l?0:(l=n,printf("\n"));
    }
    return 0;
}