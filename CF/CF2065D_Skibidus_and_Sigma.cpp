// https://codeforces.com/contest/2065/problem/D
// #排序 #数学
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define int long long

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<vector<int>, int>> num_data;
    for(int i = 0; i < n; ++i){
        vector<int> row;
        int sum = 0;
        for(int i = 0; i < m; ++i){
            int num; cin >> num;
            row.push_back(num);
            sum += num;
        }
        num_data.emplace_back(make_pair(row, sum));
    }
    sort(num_data.begin(), num_data.end(), [](const pair<vector<int>, int>&lhs, const pair<vector<int>, int>& rhs)-> bool {
        return lhs.second > rhs.second;
    });
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans += (m*n-(i*m+j))*num_data[i].first[j];
        }
    }
    cout << ans << '\n';
    return;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}