#include <algorithm>
#include <iostream>
#define int long long
using namespace std;

int ans = 0;

void gcd(int a, int b){
    if(a > b){
        swap(a, b);
    }
    int cnt = b/a;
    ans += cnt*a*4;
    
    if(b%a){
        gcd(b%a, a);
    }
}


signed main(){
    int x, y;
    cin >> x >> y;
    gcd(x, y);
    cout << ans;
}