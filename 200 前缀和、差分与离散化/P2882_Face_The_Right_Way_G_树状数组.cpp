#include <iostream>
#include <memory.h>
using namespace std;
const int MAX_SIZE = 1e4+30;

int n;
int num[MAX_SIZE];

int tree_node_copy[MAX_SIZE];
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
        char input; cin >> input;
        num[i] = (input == 'F');
    }
    for(int i = 1; i <= n; ++i){
        add(i, num[i]-num[i-1]);
    }
    memcpy(tree_node_copy, tree_node, sizeof(int)*MAX_SIZE);

    int M = 0x3f3f3f3f;
    int K;
    for(int i = 1; i <= n; ++i){
        memcpy(tree_node, tree_node_copy, sizeof(int)*MAX_SIZE);
        int yes = 1;
        int the_m = 0;
        for(int j = 1; j <= n; ++j){
            int now = asum(j); now%=2;
            if(now == 0){
                if(j+i-1 > n){//out of range
                    yes = 0; break;
                }else{
                    add(j, 1);
                    add(j+i, -1);
                    the_m ++;
                }
            }
        }
        if(yes){
            if(the_m < M){
                M = the_m;
                K = i;
            }
        }
    }
    cout << K << ' ' << M;
    return 0;
}