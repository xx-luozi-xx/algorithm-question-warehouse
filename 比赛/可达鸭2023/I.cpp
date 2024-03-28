#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);

void win1(){
    cout << "Nitori Win\n";
}
void win2(){
    cout << "Takane Win\n";
}
void draw(){
    cout << "Draw\n";
}
signed main(){
    int n; cin >> n;
    for(int nn = 0; nn < n; ++nn){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(r1<l2){//2win
            win2();
            continue;
        }else 
        if(r2<l1){//1win
            win1();
            continue;
        }else 

        if(l1 <= l2 and r2 <= r1){
            int win_1 = r1-r2;
            int win_2 = l2-l1;
            if(win_1 > win_2){
                win1();
            }else if(win_1 == win_2){
                draw();
            }else{
                win2();
            }
            continue;
        }else 

        if(l2 <= l1 and r1 <= r2){
            int win_1 = l1-l2;
            int win_2 = r2-r1;
            if(win_1 > win_2){
                win1();
            }else if(win_1 == win_2){
                draw();
            }else{
                win2();
            }
            continue;
        }else 

        if(r1<r2){
            win2();
        }else
        if(r2 < r1){
            win1();
        }


    }
    return 0;
}