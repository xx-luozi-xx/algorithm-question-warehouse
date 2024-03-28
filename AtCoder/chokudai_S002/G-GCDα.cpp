#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    return EXIT_SUCCESS;
}