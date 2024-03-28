#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a1, a2;
    long long b1, b2;
    scanf("%lld/%lld", &a1, &a2);
    scanf("%lld/%lld", &b1, &b2);

    a1*=b1;
    a2*=b2;

    long long gcd = __gcd(a1,a2);
    a1/=gcd, a2/=gcd;

    cout << a2 << ' ' << a1;
    return 0;
}