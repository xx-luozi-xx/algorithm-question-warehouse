#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 30;

int N;
int bag[MAX_N], bag_size = 0;

int ans[1000];

inline void check()noexcept{
    int asum = bag[0];
    int ans_ = 0;
    for(int i = 1; i < bag_size; ++i){
        ans_ += bag[i] * asum;
        asum += bag[i];
    }
    ans[ans_] = 1;
}

void g(int sum, int up)noexcept{
    if(sum == 0){
        check();
    }else{
        for(int i = 1; i <= sum; ++i){
            if(i > up) continue;

            bag[bag_size++] = i;
            g(sum-i, min(up, i));
            bag_size--;
        }
    }
}

int main(){
    cin >> N;
    g(N, N);
    int ans_ = 0;
    for(int i = 0; i < 1000; ++i){
        ans_ += ans[i];
    }
    cout << ans_;
    return 0;
}