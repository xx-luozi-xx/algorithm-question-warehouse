#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e6+30;
int n;
vector<int> eage[MAX_SIZE];

int fa[MAX_SIZE];
void make_fa(int now, int father)noexcept{
    fa[now] = father;
    for(int itr : eage[now]){
        if(itr != father){
            make_fa(itr, now);
        }
    }
}

int dp[MAX_SIZE];
void make_dp(int now)noexcept{
    if(eage[now].size() == 1 and now != 1){//leaf
        dp[now] = 1;
    }else{
        int max_ = 0;
        for(int itr : eage[now]){
            if(itr != fa[now]){
                make_dp(itr);
                max_ = max(max_, dp[itr]);
            }
        }
        dp[now] = max_ + 1;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int b1, b2; cin >> b1 >> b2;
        if(b1){
            eage[i].push_back(b1);
            eage[b1].push_back(i);
        }
        if(b2){
            eage[i].push_back(b2);
            eage[b2].push_back(i);
        }
    }

    make_fa(1, -1);
    make_dp(1);
    cout << dp[1];
    return 0;
}