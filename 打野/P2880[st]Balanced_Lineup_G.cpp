#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;
const int MAX_SIZE = 5e4+30;
const int MAX_BIT = log2(MAX_SIZE)+1;
int n, q;
int num[MAX_SIZE];
int log_2[MAX_SIZE];

void log2_init(){
    for(int i = 2; i < MAX_SIZE; i *= 2){
        log_2[i] = 1;
    }
    for(int i = 1; i < MAX_SIZE; ++ i){
        log_2[i] += log_2[i-1];
    }
}

int st_max[MAX_SIZE][MAX_BIT];
int st_min[MAX_SIZE][MAX_BIT];

int main(){
    log2_init();
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }
    for(int i = 0; i < n; ++i){
        st_max[i][0] = num[i];
        st_min[i][0] = num[i];
    }
    for(int i = 1; i < MAX_BIT; ++i){
        for(int j = 0; j < n and j+(1<<(i-1)) < n; ++j){
            st_max[j][i] = max(st_max[j][i-1], st_max[j+(1<<(i-1))][i-1]);
            st_min[j][i] = min(st_min[j][i-1], st_min[j+(1<<(i-1))][i-1]);
        }
    }
    auto max_q = [](int l, int r)->int {
        assert(l <= r);
        int len = log_2[r-l+1];
        return max(st_max[l][len], st_max[r-((1<<len)-1)][len]);
    };
    auto min_q = [](int l, int r)->int {
        assert(l <= r);
        int len = log_2[r-l+1];
        return min(st_min[l][len], st_min[r-((1<<len)-1)][len]);
    };
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << max_q(l, r)-min_q(l, r) << '\n';
    }
    return 0;
}