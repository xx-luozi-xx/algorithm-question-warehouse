#include <iostream>
#define int long long
using namespace std;

inline int b(int num, int idx){
    idx--;
    return (num>>idx)&1ll;
}
inline int lb(int num){
    return num&-num;
}
signed main(){
    int n, q; cin >> n >> q;
    int sum = 0;
    while(q--){
        int k; cin >> k;
        if(b(n, k) == 0){
            if(n%(1ll<<(k-1)) == 0){
                sum += 1ll<<(k-1);
                n += 1ll<<(k-1);
            }else{
                while(b(n, k) == 0){
                    sum += lb(n);
                    n += lb(n);
                }
            }
        }

    }
    cout << sum;
    return 0;
}