#include <stdio.h>
char cg[233];
int ans;
int main(){
    int n;
    char a[233];
    scanf("%d",&n);
    scanf("\n");
    scanf("%s",a);
    for(int i=0;i<n-1;i++){
        if(a[i]=='V'&&a[i+1]=='K'){
            a[i]='l',a[i+1]='l';
            i++,ans++;
        }
    }
    for(int i = 0;i < n-1; i++){
        if(a[i]==a[i+1]&&a[i]!='l'){
            ans++;
            break;
        }
    }
  
    return 0*printf("%d",ans);
}
