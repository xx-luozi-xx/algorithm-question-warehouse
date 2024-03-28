//* 之前尝试打表失败了……代码过长
#include <stdio.h>

long long f[23][23][23]{};
void init(){   
    for(int i = 0; i <= 20; ++i){
        for(int j = 0; j <= 20; ++j){
            for(int k = 0; k <= 20; ++k){
                if(i <= 0 || j <= 0 || k <= 0){
                    f[i][j][k] = 1;
                }else if(i>20||j>20||k>20){
                    //return 
                }else if(i<j&&j<k){
                    f[i][j][k] = f[i][j][k-1]+f[i][j-1][k-1]-f[i][j-1][k];
                    //w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)。
                }else{
                    f[i][j][k] = f[i-1][j][k]+f[i-1][j-1][k]+f[i-1][j][k-1]-f[i-1][j-1][k-1];
                    //w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
                }
            }
        }
    }
}

int main(){
	init();
    while(1){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        printf("w(%d, %d, %d) = ", a, b, c);
        if(a<=0 || b <= 0 ||c <=0){
            printf("%d\n", 1);
        }else if(a>20||b>20||c>20){
            printf("%d\n", f[20][20][20]);
        }else{
            printf("%d\n", f[a][b][c]);
        }
    }
    return 0;
}
