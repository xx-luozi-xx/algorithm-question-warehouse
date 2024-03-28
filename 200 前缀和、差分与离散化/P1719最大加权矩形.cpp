#include <iostream>
#include <algorithm>
#define cin ::cin
#define cout ::cout
#define int long long
using namespace std;
const int MAX_N = 150;

int n;

int info[MAX_N][MAX_N];
int asum[MAX_N][MAX_N];

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> info[i][j];
            asum[i][j] = info[i][j] + asum[i][j-1] + asum [i-1][j] - asum[i-1][j-1];
        }
    }

    int ans = -0x3f3f3f3f;

    for(int i1 = 1; i1 <= n; ++i1){
        for(int j1 = 1; j1 <= n; ++j1){
            for(int i2 = i1; i2 <= n; ++i2){
                for(int j2 = j1; j2 <= n; ++j2){
                    ans = max(asum[i2][j2] - asum[i2][j1-1] - asum[i1-1][j2] + asum[i1-1][j1-1], ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}   