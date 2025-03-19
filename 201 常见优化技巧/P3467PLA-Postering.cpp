// https://www.luogu.com.cn/problem/P3467
#include <iostream>
#include <list>
using namespace std;
const int MAX_SIZE = 250000+30;

int n;
int h[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int w, h_; cin >> w >> h_;
        h[i] = h_;
    }

    int ans = n;
    list<int> stk;
    for(int i = 0; i < n; ++i){
        while(!stk.empty() and stk.back() > h[i]){
            stk.pop_back();
        }
        if(!stk.empty() and stk.back() == h[i]){
            ans --;
        }
        stk.push_back(h[i]);
    }
    cout << ans;
    return 0;
}