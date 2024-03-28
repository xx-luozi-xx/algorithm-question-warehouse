#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0;
    long long sum = 0;
    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        ans+=(a+b-8);
        sum+=ans;
    }
    cout << sum;
    return 0;
}