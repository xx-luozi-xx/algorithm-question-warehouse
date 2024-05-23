/*
单调栈
尼玛卡常要开sync
尼玛卡空间不能直接开longlong
https://www.matiji.net/exam/dohomework/6418/2
*/
#include <iostream>
#include <stack>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 5e6+7;
const int MOD = 99887765;
const int INF = 0x3f3f3f3f;

long long n, base;
int num[MAX_SIZE];
int r[MAX_SIZE];

inline long long mod(long long a){
    if(a < 0){
        a += (-a/MOD+1ll)*MOD;
    }
    return a%MOD;
}

signed main(){
    cin >> n >> base;
    for(int i = 1; i <= n+1; ++i){
        cin >> num[i];
    }
    stack<int> stk; //num
    stk.push(-INF);
    for(int i = n+1; i >= 1; --i){
        while(stk.top() >= num[i]){
            stk.pop();
        }
        r[i] = stk.top();
        if(r[i] == -INF){
            r[i] = 0;
        }
        stk.push(num[i]);
    }
    long long ans = 0;
    long long base_now = 1;
    for(int i = n+1; i >= 1; --i){
        ans += mod(mod(r[i])*base_now);
        ans = mod(ans);
        base_now *= base;
        base_now = mod(base_now);
    }
    cout << mod(ans);
    return 0;
}