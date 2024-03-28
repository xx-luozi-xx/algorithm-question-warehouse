#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0); 
const int MAX_SIZE = 65536;
int n;
set<int> st;

int main(){
    cin >> n;
    int ans = 0;
    {   
        int a; cin >> a;
        ans += a;
        st.insert(a);
    }
    for(int i = 2; i <= n; ++i){
        int a; cin >> a;
        auto itr = st.lower_bound(a);
        int min_ = 0x3f3f3f3f;
        if(itr != st.end()){
            min_ = min(min_, abs(*itr - a));
        }
        if(itr != st.begin()){
            --itr;
            min_ = min(min_, abs(*itr - a));
        }
        ans += min_;
        st.insert(a);
    }
    cout << ans;
    return 0;
}
