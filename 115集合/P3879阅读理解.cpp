#include <set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);

int main(){
    unordered_map<string, set<int>> info;
    int n; cin >> n;
    string str;
    for(int i = 1; i <= n; ++i){
        int l; cin >> l;
        for(int j = 1; j <= l; ++j){
            cin >> str;
            info[str].insert(i);
        }
    }
    int m; cin >> m;
    for(int i = 1; i <= m; ++i){
        cin >> str;
        auto& st = info[str];
        for(auto itr = st.begin(); itr != st.end(); ++itr){
            cout << *itr << ' ';
        }
        cout << '\n';
    }
    return 0;
}