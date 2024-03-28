#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, k;
vector<string> str;
string stdstr;

signed main(){
    cin >> n>> m >>k;
    for(int i = 1; i <= n; ++i){
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }    
    cin >> stdstr;
    int ans = 0;
    for(auto itr = str.begin(); itr != str.end(); ++itr){
        int the_k = 0;
        for(int i = 0; i < m; ++i){
            the_k += ((*itr)[i]!=stdstr[i]);
        }
        ans += (the_k <= k);
    }
    cout << ans;
    return 0;
}