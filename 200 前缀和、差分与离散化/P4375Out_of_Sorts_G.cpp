#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1e5+30;

int n;
int num[MAX_SIZE];

int disc[MAX_SIZE];
int disc_size = 0;

int tree_node[MAX_SIZE];
inline int lowbit(int x)noexcept{
    return x&-x;
}
inline void add(int idx, int data)noexcept{
    while(idx < MAX_SIZE){
        tree_node[idx] += data;
        idx += lowbit(idx);
    }
}
inline int asum(int idx)noexcept{
    int ret = 0;
    while(idx){
        ret += tree_node[idx];
        idx ^= lowbit(idx);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        disc[disc_size++] = num[i];
    }
    sort(disc, disc+disc_size);
    //disc_size = unique(disc, disc+disc_size) - disc;
    for(int i = 1; i <= n; ++i){
        num[i] = lower_bound(disc, disc+disc_size, num[i]) - disc+1;
        //printf("(%d)", num[i]);
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        add(num[i], 1);
        ans = max(ans, i-asum(i));
        //printf("[%d]", asum(i));
    }
    cout << ans;
    return 0;
}
