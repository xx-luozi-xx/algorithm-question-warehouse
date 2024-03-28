#include <iostream>
using namespace std;


int main(){
    long long ans = 0;
    for(int i = 0; i < 6; ++i){
        long long a; cin >> a;
        ans += a;
    }
    cout << ans;
    return 0;
}