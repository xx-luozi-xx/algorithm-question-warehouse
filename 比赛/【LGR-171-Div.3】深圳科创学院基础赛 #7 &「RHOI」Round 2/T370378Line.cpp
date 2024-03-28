#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T-->0){
        int xa, ya, xb, yb, xc, yc, xd, yd;
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        int ans = 2;
        if(yc <= ya and ya <= yd){
            ans--;
        }
        if(xa <= xc and xc <= xb){
            ans --;
        }
        cout << ans << '\n';
    }
}