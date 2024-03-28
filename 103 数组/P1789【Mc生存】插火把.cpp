#include <stdio.h>
bool a[100+30][100+30];
int n,k,m;

int light(int x,int y,int n){
return x>=0&&x<n&&y>=0&&y<n?a[x][y]=1:0;
}
void huoba(int x,int y,int n){
    for(int i=-2;i<=2;i++){
        light(x,y+i,n),light(x+i,y,n);
    }
    for(int i=-1;i<=1;i+=2){
        for(int j=-1;j<=1;j+=2){
            light(x+i,y+j,n);
        }
    }
}
void yingshi(int x,int y,int n){
    for(int i=-2;i<=2;i++){
        for(int j=-2;j<=2;j++){
            light(x+i,y+j,n);
        }
    }
}
int main(){
    scanf("%d %d %d",&n, &k, &m);
    int x,y;
    for(int i=0;i<k;i++){
        scanf("%d %d",&x, &y);
        huoba(x-1,y-1,n);//处理边界
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&x, &y);
        yingshi(x-1,y-1,n);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          //  printf("%d ",(int)a[i][j]);
            ans+=a[i][j];
        }
     //   printf("\n");
    }
    return 0*printf("%d",n*n-ans);
}