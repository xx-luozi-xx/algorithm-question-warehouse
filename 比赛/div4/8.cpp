#include <iostream>
using namespace std;
const int MAX_N = 11;
const int MAX_K = 105;
int dp[MAX_N][MAX_K];
int asum[MAX_N][MAX_K];
int n, k;
int main(){
    n = 8;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int l = 0; l <= i-1; ++l)
        for(int j = 1; j <= 64; ++j){
            for(int k = 1; k <= 9; ++k){
                if(j-k>=0){
                    dp[i][j]+=dp[l][j-k];    
                }
            }
        }
    }
    dp[0][0]=0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 64; ++j){
            asum[i][j] = asum[i-1][j]+asum[i][j-1]-asum[i-1][j-1]+dp[i][j];
        }
    }
    int T; cin >> T;
    while((T--)){
        cin >> n >> k;
        cout << asum[n][min(k,64)] << '\n';
    }
}
