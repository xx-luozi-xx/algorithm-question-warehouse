#include <bits/stdc++.h>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;
const int MOD = 1e9+7;

int n;
int num[MAX_SIZE];

int tree[MAX_SIZE];
inline int lb(int x)noexcept{
    return x&-x;
}
inline void add(int idx, int rhs)noexcept{
    while(idx < MAX_SIZE){
        tree[idx] += rhs;
        idx += lb(idx);
    }
}
inline int asum(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret += tree[idx];
        idx ^= lb(idx);
    }
    return ret;
}

int jie[MAX_SIZE];
int jie_init(){
    jie[0] = 1;
    for(int i = 1; i < MAX_SIZE; ++i){
        jie[i] = jie[i-1]*i;
        jie[i] %= MOD;
    }
    return 0;
}
int jie_init_ = jie_init();

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        add(num[i], 1);
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += asum(num[i]-1)*jie[n-i];
        ans %= MOD;
        add(num[i], -1);
    }
    cout << ans+1;
    return 0;



}