// https://codeforces.com/contest/2065/problem/C2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        a.push_back(num);
    }
    for(int i = 0; i < m; ++i){
        int num; cin >> num;
        b.push_back(num);
    }
    sort(b.begin(), b.end());
    a[0] = min(b[0]-a[0], a[0]);
    for(int i = 1; i < n; ++i){
        bool allow_not_change = false;
        if(a[i-1] <= a[i]){
            allow_not_change = true;
        }
        auto itr = lower_bound(b.begin(), b.end(), a[i]+a[i-1]);
        if(itr == b.end() and allow_not_change==false){
            cout << "NO\n";
            return;
        }else if(itr == b.end() and allow_not_change==true){
            void();
        }else if(itr != b.end() and allow_not_change==false){
            a[i] = *itr-a[i];
        }else if(itr != b.end() and allow_not_change==true){
            a[i] = min(*itr-a[i], a[i]);
        }
    }
    cout << "YES\n";
    return;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
