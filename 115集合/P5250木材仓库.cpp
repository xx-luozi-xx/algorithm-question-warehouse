#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    set<int> st;
    while(n--){
        int op, len; cin >> op >> len;
        if(op == 1){
            if(st.count(len)){
                cout << "Already Exist\n";
            }else{
                st.insert(len);
            }
        }else if(op == 2){
            if(st.empty()){
                cout << "Empty\n";
            }else{
                auto itr = st.lower_bound(len);
                if(itr == st.end()){
                    itr--;
                    cout << *itr << '\n';
                    st.erase(itr);
                }else if(itr == st.begin()){
                    cout << *itr << '\n';
                    st.erase(itr);
                }else{
                    auto itr_ = itr--;
                    if(abs(*itr - len) <= abs(*itr_ - len)){
                        cout << *itr << '\n';
                        st.erase(itr);
                    }else{
                        cout << *itr_ << '\n';
                        st.erase(itr_);
                    }
                }
            }
        }
    }
    return 0;
}