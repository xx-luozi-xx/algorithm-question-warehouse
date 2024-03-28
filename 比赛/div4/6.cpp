#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 1000+30;

int n, m, k;
int a[MAX_SIZE][MAX_SIZE];

signed main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            a[i][j]-=j*k;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        int tmp = -0x3f3f3f3f3f3f3f3f;
        for(int j = 1; j <= m; ++j){
            tmp = max(tmp, a[i][j]);
        }
        ans += tmp;
    }
    cout << ans;
}