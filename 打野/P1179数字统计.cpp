#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, l; cin >> r >> l;
    long long ans = 0;
    for(int i = r; i <= l; ++i){
        int j = i;
        while(j){
            ans += ((j%10) ==2);
            j/=10;
        }
    }
    cout << ans;
    return 0;
}