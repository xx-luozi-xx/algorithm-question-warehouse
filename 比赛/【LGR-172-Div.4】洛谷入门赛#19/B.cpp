#include <iostream>
#define int long long
using namespace std;

signed main(){
    int T; cin >> T;
    while(T--){
        int N, k;
        cin >> N >> k;
        if((1+k)*k/2 <= N){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
    return 0;
}