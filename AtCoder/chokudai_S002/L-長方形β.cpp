//离散化
//长方形竖过来
//按长边排序
//树状数组求最大上升子序列
#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2*(2e5+30);
int n;
pair<int, int> save[MAX_SIZE];
int num[MAX_SIZE], num_size = 0;
unordered_map<int, int> to_me;

int tree[MAX_SIZE];
inline int lb(int x)noexcept{
    return x&-x;
}
inline void add(int idx, int num)noexcept{
    while(idx < MAX_SIZE){
        tree[idx] = max(tree[idx], num);
        idx += lb(idx);
    }
}
inline int asum(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret = max(ret, tree[idx]);
        idx ^= lb(idx);
    }
    return ret;
}
int dp[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> save[i].first >> save[i].second;
        if(save[i].first < save[i].second){
            swap(save[i].first, save[i].second);
        }
        num[num_size++] = save[i].first;
        num[num_size++] = save[i].second;
    }
    sort(num, num + num_size);
    num_size = unique(num, num + num_size) - num;
    for(int i = 0; i < num_size; ++i){
        to_me.insert({num[i], i+1});
    }
    for(int i = 1; i <= n; ++i){
        save[i].first = to_me[save[i].first];
        save[i].second = to_me[save[i].second];
    }
    sort(save+1, save+1+n);
    
    int ans = 0;
    queue<pair<pair<int, int>, int>>que;
    for(int i = 1; i <= n; ++i){
        if(!que.empty() and save[i].first > que.front().first.first){
            while(!que.empty()){
                add(que.front().first.second, dp[que.front().second]);
                que.pop();
            }
        }
        
        dp[i] = max(1, asum(save[i].second-1)+1);

        que.push({save[i], i});
    }

    for(int i = 1; i <= n; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}

