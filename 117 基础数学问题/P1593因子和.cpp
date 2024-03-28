#include <iostream>
#define int long long
using namespace std;

const int MOD = 9901;
const int MAX_SIZE = 5e7;

int prime[10000];
int times[10000];
int prime_size = 0;

inline int qpow(int a, int b)noexcept{
    int ret = 1;
    while(b){
        if(b%2 == 1){
            ret *= a; ret %= MOD;
            b--;
        }
        a*=a; a %= MOD;
        b/=2;
    }
    return ret%MOD;
}

inline int div(int a)noexcept{
    return qpow(a, MOD-2);
}

inline int formal(int a){
    return (a+MOD)%MOD;
}
signed main(){
    int a, b; cin >> a >> b;
    for(int i = 2; i < MAX_SIZE; ++i){
        if(a%i == 0){
            prime[prime_size] = i;
            while(a%i == 0){
                times[prime_size] ++;
                a/=i;
            }
            prime_size ++;
        }
    }

    for(int i = 0; i < prime_size; ++i){
        times[i] *= b;
    }

    int ret = 1;
    for(int i = 0; i < prime_size; ++i){
        if((prime[i]-1)%MOD == 0){
            ret *= times[i]+1;
        }else{
            ret *= (formal(qpow(prime[i], times[i]+1)-1)*div(prime[i]-1))%MOD;
        }
        ret %= MOD;
    }
    cout << ret;
}