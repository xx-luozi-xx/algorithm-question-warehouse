#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0;
    unordered_map<string, int> mp;
    while(n--){
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        if(a!=b)
            ans += mp[b+a];
        mp[a+b]++;
    }
    cout << ans;
    return 0;
}