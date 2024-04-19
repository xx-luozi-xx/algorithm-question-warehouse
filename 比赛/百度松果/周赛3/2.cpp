//dp https://www.matiji.net/exam/brushquestion/26/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int MAX_SIZE = 1e5+30;
int n;
int x[MAX_SIZE];
int h[MAX_SIZE];

enum T{
    L, R, N
};

int dp[MAX_SIZE][5];

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x[i] >> h[i];
    }
    x[n+1] = 0x3f3f3f3f3f3f3f3f;
    x[0] = -0x3f3f3f3f3f3f3f3f;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        dp[i][N] = max(max(dp[i-1][L], dp[i-1][R]), dp[i-1][N]);
        dp[i][L] = (x[i]-h[i] <= x[i-1])?(
                        0
                    ):(
                        max(max(dp[i-1][L], dp[i-1][N])+1, 
                            (x[i]-h[i])<= x[i-1]+h[i+1]?(
                                0
                            ):(
                                dp[i-1][R]+1
                            )
                        )
                    );
        dp[i][R] =  x[i]+h[i] >= x[i+1]?(
                        0
                    ):(
                        dp[i][N] + 1 
                    );
        ans = max(ans, dp[i][L]);
        ans = max(ans, dp[i][R]);
        ans = max(ans, dp[i][N]);
    }
    cout << ans;
    return 0;
}