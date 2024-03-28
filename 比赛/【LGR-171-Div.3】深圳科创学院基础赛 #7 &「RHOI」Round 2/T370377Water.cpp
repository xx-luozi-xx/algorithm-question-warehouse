#include <iostream>
#define int long long
using namespace std;

signed main(){
    int a, b, n;
    cin >> a >> b >> n;
    int t = min(a/b,n);
    cout << t*b;
}