// https://codeforces.com/problemset/problem/2082/B
// 贪心
#include <iostream>
#include <assert.h>
using namespace std;

signed main(){
    int T; cin >> T;
    while(T--){
        int x, n, m;
        cin >> x >> n >> m;
        n = min(30, n);
        m = min(30, m);
        int max_ans = x, min_ans = x;
        max_ans >>= n;
        for(int i = 0; i < m; ++i){
            max_ans = (max_ans+1)>>1;
            min_ans = (min_ans+1)>>1;
        }
        min_ans >>= n;
        cout << min_ans << ' ' << max_ans << '\n';
    }
    return 0;
}