#include <stdio.h>
int s[30][30][30];
int a,b,c;
int x1,x2,y1,y2,z1,z2;
int n;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                s[i][j][k]=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                for(int k=z1;k<=z2;k++)
                    s[i][j][k]=0;
    }
    n=0;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                n+=s[i][j][k];
    return 0*printf("%d",n);
}