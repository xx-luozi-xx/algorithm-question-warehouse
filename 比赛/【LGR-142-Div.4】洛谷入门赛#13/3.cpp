#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
unsigned long long ans;

int main(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n;++i){
        int a; cin >> a;
        ans += x+a;
    }
    cout << ans;
    return 0;
}