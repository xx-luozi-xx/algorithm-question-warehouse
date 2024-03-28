#include <stdio.h>
#include <algorithm>

int a[10000+233],n,ans,x[50000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;scanf("%d",&a[i++]));
    std::sort(a,a+n);
 /*   for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            for(int j=i;j<n-1;j++){
                a[j]==a[j+1];
            }
            n--;
        }
    }*/
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]==a[k]&&x[a[k]]==0){
                    ans++;
                    x[a[k]]=1;
                    break;
                }else if(a[i]+a[j]<a[k]){
                    break;
                }
            }
        }
    }
    return 0*printf("%d",ans);
}