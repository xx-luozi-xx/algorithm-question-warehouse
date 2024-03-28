#include <bits/stdc++.h>
using namespace std;

int main(){
    int o_data;
    int data; cin >> data; o_data = data;
    int base; cin >> base;
    string ans;
    while(data){
        int hi = data/base;
        int lo = data%base;
        if(lo < 0){
            hi += 1;
            lo -= base;
        }
        ans.push_back(lo < 10 ? ('0'+lo):(lo-10+'A'));
        data = hi;
    }
    cout << o_data << '=';
    for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr){
        cout << *itr;
    }
    cout << "(base" << base << ')';
    return 0;
}