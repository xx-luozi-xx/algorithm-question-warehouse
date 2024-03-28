#include <iostream>
#include <map>
#include <algorithm>
#define int long long
using namespace std;
const int MAX_SIZE = 1e5+30;
int n, k;
int num[MAX_SIZE];
int pre[MAX_SIZE];

int hp[MAX_SIZE];
int hp_size = 0;

int tree[MAX_SIZE];
inline int lb(int a){
    return a&-a;
}
inline int sum(int idx){
    int ret = 0;
    while(idx){
        ret += tree[idx];
        idx^=lb(idx);
    }
    return ret;
}
inline void add(int idx, int val){
    while(idx < MAX_SIZE){
        tree[idx] += val;
        idx += lb(idx);
    }
}

signed main(){
    cin >> n >> k;
    hp[hp_size++] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        pre[i] = pre[i-1] + num[i];
        hp[hp_size++] = pre[i];
    }

    sort(hp, hp+hp_size);
    hp_size = unique(hp, hp+hp_size)-hp;
    map<int, int> to_me;
    for(int i = 0; i < hp_size; ++i){
        to_me.insert({hp[i], i+1});
        //printf("[%d->%d]\n", hp[i], i+1);
    }

    add(to_me[0],1);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int key = pre[i]-k;
        auto itr = to_me.upper_bound(key);
        if(itr != to_me.begin()){
            itr--;
            ans += sum(itr->second);
            //printf("(i=%d,sum=%d)\n", i, sum(itr->second));
        }

        add(to_me[pre[i]],1);
    }
    cout << ans;
    return 0;
}