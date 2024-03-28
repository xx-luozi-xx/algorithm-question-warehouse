#include <iostream>
#include <set>
using namespace std;
const int MAX_SIZE = 1e6+30;
int n;
int num[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }
    int max_len = 0;
    int l = 0; int r = 0;
    set<int> st;
    while(r < n){
        if(st.count(num[r]) == 0){
            max_len = max(max_len, r-l+1);
            st.insert(num[r]);

            r++;
        }else{
            while(st.count(num[r])){
                st.erase(num[l]);
                l++;
            }
            
            max_len = max(max_len, r-l+1);
            st.insert(num[r]);
            r++;
        }
    }
    cout << max_len;
    return 0;
}