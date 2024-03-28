#include <stdio.h>
char a[233][233];
int X,Y;
int main(){
    scanf("%d %d",&Y,&X);
    for(int y = 0;y<Y;y++){
        scanf("\n");
        for(int x = 0;x<X;x++){
            scanf("%c",&a[x][y]);
            a[x][y]!='*'?a[x][y]='0':0;
        }
    }
    for(int y = 0; y<Y;y++){
        for(int x = 0; x<X;x++){
            if(a[x][y]=='*'){
                for(int i = -1;i<=1;i++){
                    for(int j = -1;j<=1;j++){
                        x+i>=0&&x+i<X&&y+j>=0&&y+j<Y&&a[x+i][y+j]!='*'?a[x+i][y+j]++:0;
                    }
                }
            }
        }
    }
    for(int y = 0;y<Y;y++){
        for(int x = 0;x<X;x++){
            printf("%c",a[x][y]);
        }
        y==Y-1?0:printf("\n");
    }
}