#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;
int n;
int data_[MAX_SIZE];

int tree[MAX_SIZE];
inline int lb(int x)noexcept{
    return x&-x;
}
void push(int idx, int num)noexcept{
    while(idx < MAX_SIZE){
        tree[idx] = max(tree[idx], num);
        idx += lb(idx);
    }
}
int find(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret = max(ret, tree[idx]);
        idx^=lb(idx);
    }
    return ret;
}

int dp[MAX_SIZE];
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> data_[i];
    }
    for(int i = 1; i <= n ; ++i){
        dp[i] = max(1, find(data_[i]-1)+1);
        push(data_[i], dp[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}