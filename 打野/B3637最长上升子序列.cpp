#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cout.tie(0), cin.tie(0), 0);
const int MAX_N = 1e5+10;
const int MAX_SIZE = 1e6+10;

int n;
int num[MAX_N];

int dp[MAX_N];

int tree[MAX_SIZE];
inline int lb(int x)noexcept{
    return x&-x;
}
inline int updata(int idx, int val)noexcept{
    while(idx < MAX_SIZE){
        tree[idx]=max(tree[idx], val);
        idx += lb(idx);
    }
}
inline int amax(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret = max(ret, tree[idx]);
        idx ^= lb(idx);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }

    int ans = 0;
    for(int i = 1; i <=n; ++i){
        dp[i] = amax(num[i]-1)+1;
        updata(num[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}