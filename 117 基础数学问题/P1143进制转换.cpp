#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int d_in; cin >> d_in;
    string info_str; cin >> info_str;
    int info = 0;
    for(int i = 0; i < info_str.size(); ++i){
        info *= d_in;
        info += isdigit(info_str[i])?info_str[i]-'0':(info_str[i]-'A'+10);
    }
    int d_out; cin >> d_out;
    string out_str;
    while(info){
        int out = info%d_out;
        info /= d_out;
        out < 10 ? out_str.push_back(out+'0'):out_str.push_back(char(out-10+'A'));
    }
    for(auto itr = out_str.rbegin(); itr != out_str.rend(); ++itr){
        cout << *itr;
    }
    return 0;
}