#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cout.tie(0), cin.tie(0) ,0);
const int MAX_N = 1e4+30;

int n;

vector<int> eage[MAX_N];
int time_[MAX_N];


int ans[MAX_N];

int dfs(int now)noexcept{
    if(ans[now]) return ans[now];

    int max_ans = time_[now];
    for(int i = 0; i < eage[now].size(); ++i){
        max_ans = max(dfs(eage[now][i])+time_[now], max_ans);
    }
    ans[now] = max_ans;
    return max_ans;
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a, t, b; cin >> a >> t;
        time_[a] = t;
        for(cin >> b; b != 0; cin >> b){
            eage[a].push_back(b);
        }
    }

    int max_time = 0;
    for(int i = n; i > 0; --i){
        max_time = max(dfs(i), max_time);
    }
    cout << max_time;
}
