#include <stdio.h>
#include <string.h>
#include <cmath>

#define MAX_BROAD 25

long long broad[MAX_BROAD][MAX_BROAD]{};

int main(){
    int X, Y;
    int hx, hy;
    scanf("%d %d %d %d", &X, &Y, &hx, &hy);
    broad[0][0] = 1;
    broad[hy][hx] = -1;
    for(int i = -2; i <=2; ++i){
        for(int j = -2; j <=2; ++j){
            if(abs(i*j)==2){
                if(hy+i>=0&&hx+j>=0){
                    broad[hy+i][hx+j] = -1;
                }
            }
        }
    }
    for(int i = 0; i <= Y; ++i){
        for(int j = 0; j <= X; ++j){
            if(broad[i][j] != -1){
                //broad[i][j] = broad[i-1][j]+ broad[i][j-1];
                long long dp1 = 0, dp2 = 0;
                if(i-1>=0){
                    dp1 = broad[i-1][j]==-1?0:broad[i-1][j];
                }
                if(j-1>=0){
                    dp2 = broad[i][j-1]==-1?0:broad[i][j-1];
                }
                broad[i][j] += dp1 + dp2;
            }
        }
    }
    printf("%lld", broad[Y][X]);
    return 0;
}