/*
单调栈
https://www.matiji.net/exam/dohomework/6418/4
题面有问题罢，不清不楚的（恼）
数据也有问题罢（恼）
*/
#include <stack>
#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 5e6+30;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
int n;
int num[MAX_SIZE];

signed main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    stack<int> stk;
    stk.push(0x3f3f3f3f3f3f3f3f);
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        while(stk.top() <= num[i]){
            stk.pop();
        }
        int cnt = stk.size()-1;
        ans += cnt;
        stk.push(num[i]);
    }
    cout << ans;
    return 0;
}