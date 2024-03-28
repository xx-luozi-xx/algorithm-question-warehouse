#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);


int main(){
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        ans += (a*b*c);
    }
    cout << (ans+m-1)/m << ' ' << (ans%m==0?m:ans%m);

    return 0;
}