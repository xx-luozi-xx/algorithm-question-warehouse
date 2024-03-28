#include <iostream>
#define int long long
using namespace std;
const int MOD = 722733748;

int qpow(int x, int y){
    int ret = 1;
    while(y){
        if(y&1){
            ret*=x; ret%=MOD;
        }
        x*=x; x%=MOD;
        y>>=1;
    }
    return ret;
}

signed main(){
    int k, a, q;
    cin >> k >> a >> q;
    cout << (qpow(a,k)*qpow(q, (k-1)*k/2))%MOD;
    return 0;
}