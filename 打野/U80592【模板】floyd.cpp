#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_N = 500+30;
const int INF = 0x3f3f3f3f3f3f3f3f;
int dp[MAX_N][MAX_N];

signed main(){
  //  ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = i == j?0:INF;
        }
    }
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        w = min(dp[a][b], w);
        dp[a][b] = w;
        dp[b][a] = w;
    }

    for(int k = 1; k <= n; ++k){
        for(int j = 1; j <= n; ++j){
            for(int i = 1; i <= n; ++i){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        int sum = 0;
        for(int j = 1; j <= n; ++j){
            if(dp[i][j]!=INF){
                sum+=dp[i][j];
                sum%=998244354;
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}