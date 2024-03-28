#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int s, x; cin >> s >> x;
    double now = 7;
    double acc = 0;

    while(acc <= s+x){
        if(acc >= s-x){
            acc+=now;
            if(acc <= s+x){
                cout << 'y';
                return 0;
            }else{
                cout << 'n';
                return 0;
            }
        }
        acc+=now;
        now*=0.98;
    }
    cout << 'n';
    return 0;
}