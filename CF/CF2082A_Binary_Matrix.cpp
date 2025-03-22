#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> M;
    for(int i = 0; i < n; ++i){
        string str; cin >> str;
        for(auto& itr : str){
            itr -= '0';
        }
        M.emplace_back(str);
    }
    int ans1 = 0;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(auto itr : M[i]){
            cnt ^= itr;
        }
        ans1 += cnt;
    }    
    int ans2 = 0;
    for(int j = 0; j < m; ++j){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt ^= M[i][j];
        }
        ans2 += cnt;
    }
    cout << max(ans1, ans2) << '\n';
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }    
    return 0;
}