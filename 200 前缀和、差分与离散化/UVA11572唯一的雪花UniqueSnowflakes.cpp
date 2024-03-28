#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        unordered_set<int> st;
        bool end = 0;
        for(int i = 1; i <= n; ++i){
            int num; cin >> num;
            if(end) continue;
            else{
                if(st.count(num)){
                    cout << st.size() <<'\n';
                    end = 1;
                }else{
                    st.insert(num);
                }
            }
        }
        if(!end){
            cout << st.size() <<'\n';
            end = 1;
        }
    }
    return 0;
}