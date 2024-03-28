//米勒拉宾素性测试
//int范围内选用{2,7,61}；
//long long范围选用{2,325,9375,28178,450775,9780504,179265022}
//能完美判断素数！这些质数都是精挑细选的！

#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int qpow(int a, int b, int mod)noexcept{
    int ret = 1;
    while(b){
        if(b&1){
            ret = (__int128)ret*a%mod;
        }
        a = (__int128)a*a%mod;
        b>>=1;
    }
    return ret;
}

bool prime_test(int num)noexcept{
    static const int A[]={2,325,9375,28178,450775,9780504,179265022};
    if(num < 3){
        return num == 2;
    }
    if( (num&1) == 0){
        return false;
    }

    int r = 0, d = num - 1;
    while(d & 1 == 0){
        r++;
        d>>=1;
    }

    for(auto a : A){
        int rc = qpow(a, d, num);
        if(rc < 2 || rc == num-1){
            continue;
        }

        bool pass = false;
        for(int i = 0; i < r; ++i){
            rc = (__int128)rc*rc%num;
            if(rc == num-1 && i != r-1){
                pass = true;
                break;
            }
            if(rc == 1){
                return false;
            }
        }
        if(!pass){
            return false;
        }
    }
    return true;
}

signed main(){

    int L, R; cin >> L >> R;

    int ans = 0;
    for(int i = L; i <= R; ++i){
        ans += prime_test(i);
        //printf("%d -> %d\n", i, prime_test(i));
    }
    cout << ans;
    return 0;
}

