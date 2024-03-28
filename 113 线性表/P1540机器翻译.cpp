#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    queue<int> que;

    int n, m;
    int ans = 0;
    cin >> m >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(st.count(x)){
            continue;
        }else{
            ans ++;
            que.push(x);
            st.insert(x);
            if(que.size() > m){
                st.erase(que.front());
                que.pop();
            }
        }
    }
    cout << ans;
    return 0;
}