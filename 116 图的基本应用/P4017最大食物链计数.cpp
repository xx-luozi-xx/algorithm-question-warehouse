#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 5e3+30;
const int MOD = 80112002;

int n, m;

vector<int> eage[MAX_N];
int d_in[MAX_N];
int d_out[MAX_N];

bool solved[MAX_N];
long long ans[MAX_N];

int get_ans(int now)noexcept{
    if(solved[now]) return ans[now];
    for(int i = 0; i < eage[now].size(); ++i){
        ans[now] += get_ans(eage[now][i]);
        ans[now] %= MOD;
    }
    solved[now] = 1;
    return ans[now];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        d_out[a]++;
        d_in[b]++;
        eage[a].push_back(b);
    }    

    for(int i = 1; i <= n; ++i){
        if(d_out[i] == 0){
            solved[i] = 1;
            ans[i] = 1;
        }
    }
    int ans_sum = 0;
    for(int i = 1; i <= n; ++i){
        if(d_in[i] == 0){
            ans_sum += get_ans(i);
            ans_sum %= MOD;
        }
    }
    cout << ans_sum;
    return 0;
}