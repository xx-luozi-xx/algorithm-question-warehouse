#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n, m, p; cin >> n >> m >> p;
        if(n == 1){
            cout << "YangQiShaoNian\n";
        }else if(n <= m+1){
            cout << "XiaoNian\n";
        }else{
            if(p == 0){
                cout << "XiaoNian\n";
            }else{
                cout << "YangQiShaoNian\n";
            }
        }   
    }
    return 0;
}