#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int MAX_SIZE = 1e5+30;

int n, k;
int num[MAX_SIZE];
int asum[MAX_SIZE];

signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        asum[i] = asum[i-1]+num[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        int j = lower_bound(asum+i, asum+n+1, k+asum[i-1])-asum;
        ans += n-j+1;
    }
    cout << ans;
    return 0;
}