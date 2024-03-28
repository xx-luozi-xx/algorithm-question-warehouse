#include <algorithm>
#include <iostream>
using namespace std;

const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);


int gcd(int a, int b){
    return b?gcd(b%a, a):a;
}

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; ++t){
        int n; cin >> n;
        int a, b; cin >> a >> b;
        b /= __gcd(a,b);
        for(int i = 0; i < n-2; ++i){
            cin >> a;
            b /= __gcd(a,b);
        }
        if(b == 1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}