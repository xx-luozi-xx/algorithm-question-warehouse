#include <stdio.h>
#include <string.h>
char first[200+30];
int n,ans,s='0';
int main(){
    scanf("%s",first);
    printf("%d ",n=strlen(first));
    if(first[0]-'0'){
        printf("0 ");
        s=1+'0';
    }
    for(int i=0;i<n;i++){
        if(first[i]==s){
            ans++;
        }else{
            printf("%d ",ans);
            ans=1,s=(s-'0'+1)%2+'0';
        }    
    }
    for(int j=0;j<n-1;j++){
        scanf("%s",first);
        for(int i=0;i<n;i++){
            if(first[i]==s){
                ans++;
            }else{
                printf("%d ",ans);
                ans=1,s=(s-'0'+1)%2+'0';
            }    
        }
    }
    return 0*printf("%d ",ans);
}