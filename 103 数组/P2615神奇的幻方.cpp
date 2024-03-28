#include <stdio.h>
int a[50][50],x,y,n;
int main(){
    scanf("%d",&n);
    x=n/2;
    a[x][y]=1;
    for(int i=2;i<=n*n;a[x][y]=i++){
        if(y==0&&x!=n-1){
            y=n-1,x++;
        }else if(x==n-1&&y!=0){
            x=0,y--;
        }else if(y==0&&x==n-1){
            y++;
        }else{
            if(!a[x+1][y-1]){
                x++,y--;
            }else{
                y++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}