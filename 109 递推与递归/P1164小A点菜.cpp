#include <stdio.h>

int val[100+5]{};
int dp[100+5][10000+5]{};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &val[i]);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(val[i] < j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-val[i]];
            }else if(val[i] == j){
                dp[i][j] = dp[i-1][j] + 1;
            }else if(val[i] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}