#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
int main(){
    int n; cin >> n;
    unordered_set<string>st;
    while(n--){
        string in; cin >> in;
        st.insert(in);
    }
    cout << st.size();
    return 0;
}