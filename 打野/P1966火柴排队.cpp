#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;
const int MOD = 1e8-3;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);

int n;
int a_data[MAX_SIZE], a_data_size;
int b_data[MAX_SIZE], b_data_size;
int a[MAX_SIZE];
int b[MAX_SIZE];

int st[MAX_SIZE];

int tree[MAX_SIZE];
inline int lb(int a)noexcept{
    return a&-a;
}
inline int sum(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret += tree[idx];
        idx ^= lb(idx);
    }
    return ret;
}
inline void add(int idx, int num) noexcept{
    while(idx < MAX_SIZE){
        tree[idx] += num;
        idx += lb(idx);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a_data[i];
        a[i] = a_data[i];
    }
    sort(a_data, a_data+n);
    a_data_size = unique(a_data, a_data+n)-a_data;
    for(int i = 0; i < n; ++i){
        a[i] = lower_bound(a_data, a_data+a_data_size, a[i]) - a_data + 1;
    }

    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> b_data[i];
        b[i] = b_data[i];
    }
    sort(b_data, b_data+n);
    b_data_size = unique(b_data, b_data+n) - b_data;
    for(int i = 0; i < n; ++i){
        b[i] = lower_bound(b_data, b_data+b_data_size, b[i]) - b_data + 1;
        mp.insert({b[i], i+1});
    }

    for(int i = 0; i < n; ++i){
        st[i] = mp[a[i]];
    }

    int ans = 0;
    for(int i = n-1; i >= 0; --i){
        ans += sum(st[i]-1); ans %= MOD;
        add(st[i], 1);
    }

    cout << ans;
    return 0;
}