#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        set<int> st;
        while(n--){
            int x; cin >> x;
            if(!st.count(x)){
                st.insert(x);
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}