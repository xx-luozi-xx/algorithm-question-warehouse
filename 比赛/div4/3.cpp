#include <iostream>
#define int long long
using namespace std;
const int MOD = 722733748;
signed main(){
    int k, a, q;
    cin >> k >> a >> q;
    int ans = a;
    int last = a;
    for(int i = 1; i < k; ++i){
        last *= q; last %= MOD;
        ans *= last; ans %= MOD;
    }
    cout << ans;
    return 0;
}