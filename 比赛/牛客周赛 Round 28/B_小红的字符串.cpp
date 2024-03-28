#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> ans;
    string str; cin >> str;
    for(int i = 0; i < int(str.size())-1; ++i){
        ans.push_back(str.substr(i,2));
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << '\n';
    }
    return 0;
}