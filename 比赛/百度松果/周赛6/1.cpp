//二维偏序，离散化，树状数组
//https://www.matiji.net/exam/dohomework/6332/1

#include <iostream>
#include <algorithm>
#include <memory.h>
#define int long long
using namespace std;
const int MAX_SIZE = 1e6+30;
const int MOD = 1e9+7;

int n, t;
int num[MAX_SIZE];
int num_tmp[MAX_SIZE];


int tree[MAX_SIZE];
inline int lb(int x){
    return x&-x;
}
void update_add(int idx, int val){
    while(idx < MAX_SIZE){
        tree[idx] += val;
        idx += lb(idx);
    }
}

int tfind(int idx){
    int ret = 0;
    while(idx){
        ret += tree[idx];
        idx ^= lb(idx);
    }
    return ret;
}

signed main(){
    cin >> n >> t;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        num[i] -= t;
        num[i] += num[i-1];
        ans += (num[i]>=0);
    }
    memcpy(num_tmp, num, sizeof(int)* MAX_SIZE);
    sort(num_tmp, num_tmp+n+1);
    auto num_tmp_end = unique(num_tmp, num_tmp+n+1);
    for(int i = 1; i <= n; ++i){
        num[i] = lower_bound(num_tmp, num_tmp_end, num[i])-num_tmp+1;
    }
    for(int i = 1; i <= n; ++i){
        ans += tfind(num[i]);
        update_add(num[i], 1);
    }
    cout << ans%MOD;
    return 0;
}