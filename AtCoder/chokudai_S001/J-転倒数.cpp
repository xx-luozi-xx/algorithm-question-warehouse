#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;
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

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    long long ans = 0;
    for(int i = n; i >= 1; --i){
        ans += asum(num[i]-1);
        add(num[i], 1);
    }
    cout << ans;
    return 0;
}