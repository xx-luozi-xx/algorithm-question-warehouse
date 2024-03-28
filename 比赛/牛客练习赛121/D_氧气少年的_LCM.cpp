#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

inline int lowbit(int x)noexcept{
    return x&-x;
}

struct Out{
    int op, x, y;
};

signed main(){
    int T; cin >> T;
    while(T--){
        vector<Out> out;
        int x, y; cin >> x >> y;
        int gcd = __gcd(x, y);
        int lcm = x*y/gcd;
        out.push_back({1, x, y});
        out.push_back({1, x, y});
        for(int i = 1; i*gcd < lcm and 2*i*gcd<(int)1e18; i*=2){
            out.push_back({2, i*gcd, i*gcd});
            out.push_back({2, i*gcd, i*gcd});
        }
        int n = lcm/gcd;
        int last = lowbit(n); n ^= lowbit(n);
        while(n){
            int nxt = lowbit(n); n ^= lowbit(n);
            out.push_back({2, last*gcd, nxt*gcd});
            last += nxt;
        }
        printf("%d\n", (int)out.size());
        for(int i = 0; i < out.size(); ++i){
            printf("%lld %lld %lld\n", out[i].op, out[i].x, out[i].y);
        }
    }
    return 0;
}