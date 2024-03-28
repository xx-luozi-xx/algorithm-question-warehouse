#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
int main(){
    int n; cin >> n;
    unordered_map<int ,int> mp;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        mp.insert({x, i});
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(mp.count(x)){
            cout << mp[x] << '\n';
        }else{
            cout << "0\n";
        }
    }
    return 0;
}