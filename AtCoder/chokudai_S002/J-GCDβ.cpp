#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2e5+30;
int a[MAX_SIZE];
int b[MAX_SIZE];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    int gcd_a = a[0];
    int gcd_b = b[0];
    for(int i = 1; i < n; ++i){
        gcd_a = max(__gcd(gcd_a, a[i]), __gcd(gcd_a, b[i]));
        gcd_b = max(__gcd(gcd_b, a[i]), __gcd(gcd_b, b[i]));
    }
    cout << max(gcd_a, gcd_b);
    return 0;
}