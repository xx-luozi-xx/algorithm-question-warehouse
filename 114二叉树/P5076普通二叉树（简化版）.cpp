#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;

int n;
int op[MAX_SIZE];
int x[MAX_SIZE];

int num[MAX_SIZE], num_size;
unordered_map<int, int> to_me;
unordered_map<int, int> to_out;
set<int> st;

int tree[MAX_SIZE];
inline int lb(int i)noexcept{
    return i&-i;
}
inline void add(int idx, int data)noexcept{
    while(idx < MAX_SIZE){
        tree[idx]+=data;
        idx+=lb(idx);
    }
}
inline int asum(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret += tree[idx];
        idx ^= lb(idx);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> op[i] >> x[i];
        num[num_size++] = x[i];
    }
    sort(num, num+num_size);
    num_size = unique(num, num+num_size) - num;
    for(int i = 0; i < num_size; ++i){
        to_me.insert({num[i], i+3});
        to_out.insert({i+3, num[i]});
    }
    for(int i = 0; i < n; ++i){
        if(op[i] != 2)
            x[i] = to_me[x[i]];
    }

    for(int i = 0; i < n; ++i){
        if(op[i] == 1){
            cout << asum(x[i]-1)+1 << '\n';
        }else if(op[i] == 2){
            int l = *st.begin();
            int r = *st.rbegin();
            int ans = -1;
            while(l <= r){
                int mid = (l+r)>>1;
                if(asum(mid) >= x[i]){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            cout << to_out[ans] << '\n';
        }else if(op[i] == 3){
            auto itr = st.lower_bound(x[i]);
            if(itr == st.begin()){
                cout << "-2147483647\n";
            }else{
                --itr;
                cout << to_out[*itr] << '\n';
            }
        }else if(op[i] == 4){
            auto itr = st.upper_bound(x[i]);
            if(itr == st.end()){
                cout << "2147483647\n";
            }else{
                cout << to_out[*itr] << '\n';
            }
        }else if(op[i] == 5){
            st.insert(x[i]);
            add(x[i], 1);
        }
    }

    return 0;
}