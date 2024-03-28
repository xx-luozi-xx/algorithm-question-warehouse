#include <iostream>
#include <algorithm>
#define int long long 
using namespace std;
const int MOD = 1e9+7;

inline int qpow(int a, int b){
    int ret = 1;
    while(b){
        if(b&1){
            ret*=a; ret%=MOD;
            b^=1;
        }else{
            a*=a; a%=MOD;
            b>>=1;
        }
    }
    return ret%MOD;
}

signed main(){
    int n, k;
    cin >> n >> k;
    int ans = qpow(k/2, n);
    if(n%3 == 0){
        ans += (qpow((k+1)/2, 2*n/3)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
    }else if(n%3 == 1){
        n--;
        ans += (qpow((k+1)/2, 2*n/3+1)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3)*qpow(k/2, n/3+1))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3+1)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
    }else{
        n-=2;
        ans += (qpow((k+1)/2, 2*n/3+1)*qpow(k/2, n/3+1))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3+1)*qpow(k/2, n/3+1))%MOD;
        ans %= MOD;
        ans += (qpow((k+1)/2, 2*n/3+2)*qpow(k/2, n/3))%MOD;
        ans %= MOD;
    }
    cout << ans;
}


