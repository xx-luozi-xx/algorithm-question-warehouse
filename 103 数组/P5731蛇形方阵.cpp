#include <stdio.h>
int a[20][20],n,i,j,k,ans=1;
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
int next0_3(int &a);
int main(){
    scanf("%d",&n);
    for(i=0;i<=n+1;i++){
        a[0][i]=a[i][0]=a[n+1][i]=a[i][n+1]=-1;
    }
    for(i=1,j=1;ans<=n*n;){
        do{
            a[i][j]=ans++;
            i+=y[k],j+=x[k];
        } while(a[i][j]==0);
        i-=y[k],j-=x[k];
        next0_3(k);
        i+=y[k],j+=x[k];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]<10?printf(" "):0;
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
}
int next0_3(int &a){
    a=(a+1)%4;
    return 0;
}