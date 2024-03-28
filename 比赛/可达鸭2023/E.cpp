#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE_ = 1e5+30;

int n;
int a[MAX_SIZE_];

signed main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);
    long long ans = 0;
    int price = 0;
    for(int i = 0; i < n; ++i){
        if((n-i)*a[i] > ans){
            ans = (n-i)*a[i];
            price = a[i];
        }
    }
    cout << ans << ' ' << price;
    return 0;
}