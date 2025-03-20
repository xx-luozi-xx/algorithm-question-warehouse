// https://codeforces.com/contest/2065/problem/E
// #构造
#include <iostream>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    char a, b;
    if(n > m){
        a = '0';
        b = '1';
    }else{
        a = '1';
        b = '0';
    }
    int a_num = max(n, m);
    int b_num = min(n, m);

    if(a_num < k or a_num-b_num>k){
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < k; ++i){
        a_num--;
        cout << a;
    }
    while(a_num){
        a_num--, b_num--;
        cout << b << a;
    }
    while(b_num){
        b_num--;
        cout << b;
    }
    cout << '\n';
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}