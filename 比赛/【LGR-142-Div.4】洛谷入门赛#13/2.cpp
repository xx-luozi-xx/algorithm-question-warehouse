#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);


int main(){
    int n; cin >> n;
    int min_ = 0x3f3f3f3f;
    int ans = -1;
    int flr[] = {3,5,9};
    for(int i = 0; i <= 2; ++i){
        int x; cin  >> x;
        if(n > flr[i]) continue;
        if(x < min_){
            ans = i;
            min_ = x;
        }
    }
    string str;
    if(ans == 0){
        str = "library";
    }else if(ans == 1){
        str = "comprehensive";
    }else{
        str= "art";
    }
    cout << str;
    return 0;
}