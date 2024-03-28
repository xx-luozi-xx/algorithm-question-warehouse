/*区间最值树状数组*/
#include <iostream>
#include <memory.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 1e6+30;

inline int lowbit(int val)noexcept{
    return val&-val;
}
int num[MAX_SIZE];
int tree_max[MAX_SIZE];
int tree_min[MAX_SIZE];
int tree_init_(){
    memset(tree_min, 0x3f, MAX_SIZE*sizeof(int));
    return 0;
}
int tree_init = tree_init_();

inline void tree_set(int idx, int val)noexcept{
    num[idx] = val;
    while(idx < MAX_SIZE){
        tree_max[idx] = max(tree_max[idx], val);
        tree_min[idx] = min(tree_min[idx], val);
        idx += lowbit(idx);
    }
}
int tree_find_max_1(int r){
    int ans = 0;
    while(r){
        ans = max(ans, tree_max[r]);
        r-=lowbit(r);
    }
    return ans;
}


int tree_find_max(int l, int r)noexcept{
    if(l == r) return num[r];
    if(l <= r-lowbit(r)){
        return max(tree_max[r], tree_find_max(l, r-lowbit(r)));
    }else{
        return max(num[r], tree_find_max(l, r-1));
    }
}
int tree_find_min(int l, int r)noexcept{
    if(l == r) return num[r];
    if(l <= r-lowbit(r)){
        return min(tree_min[r], tree_find_min(l, r-lowbit(r)));
    }else{
        return min(num[r], tree_find_min(l, r-1));
    }
}

int main(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int input; cin >> input;
        tree_set(i, input);
    }
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        cout << tree_find_max(l, r) - tree_find_min(l, r) << '\n';
    }
    return 0;
}


