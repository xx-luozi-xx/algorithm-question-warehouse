#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main(){
    int n; cin >> n;
    string str;
    for(int i = 1; i <= n; ++i){
        string in; cin >> in;
        str += in;
    }
    long long ans = 0;
    for(int i = 0; i < str.size(); ++i){
        ans*=10; ans %= MOD;
        ans+=str[i]-'0'; ans %= MOD;
    }
    cout << ans;
    return 0;
}