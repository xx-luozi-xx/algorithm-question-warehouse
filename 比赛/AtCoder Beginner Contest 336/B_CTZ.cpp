#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    int ans = 0;
    while(N%2 == 0){
        ans ++;
        N>>=1;
    }
    cout << ans;
    return 0;
}