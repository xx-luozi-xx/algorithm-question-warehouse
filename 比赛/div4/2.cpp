#include <iostream>
using namespace std;
const int CNT = 12000;
int main(){
    int T; cin >> T;
    while(T--){
        int x, y;
        cin >> x >> y;
        int sub = (y-x+1)/2;
        if(sub <= CNT){
            cout << 5 << '\n';
        }else if(sub <= 1.5*CNT){
            cout << 6 << '\n';
        }else if(sub <= 2*CNT){
            cout << 8 <<'\n';
        }else if(sub <= 3*CNT){
            cout << 11 << '\n';
        }else{
            int ans = (sub+4*CNT-1)/(4*CNT);
            cout << ans*13 << '\n';
        }
    }
}