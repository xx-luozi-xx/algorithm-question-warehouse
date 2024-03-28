#include <algorithm>
#include <iostream>
#define int long long
using namespace std;

inline int lcm(int a, int b){
    return a*b/__gcd(a,b);
}

signed main(){
    int a, b, c;
    cin >> a >> b >> c; 
    cout << lcm(a, lcm(b, c));
    return 0;
}