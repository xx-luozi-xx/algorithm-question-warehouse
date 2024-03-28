#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >>k;
    int last = 0;
    long long ans = 0;
    
    while(n){
        ans += n;
        last += n;
        n = last/k;
        last%=k;
    }
    cout << ans;
}