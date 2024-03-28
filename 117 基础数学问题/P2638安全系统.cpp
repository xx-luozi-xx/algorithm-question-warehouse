#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_SIZE = 60;

int c[MAX_SIZE][MAX_SIZE];

signed main(){

    c[0][0] = 1;
    for(int i = 1; i < MAX_SIZE; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    int n, a, b;
    cin >> n >> a >> b;

    __int128 sum1 = 0;
    for(int i = 0; i <= a; ++i){
        sum1 += c[n+i-1][n-1];
    }
    __int128 sum2 = 0;
    for(int i = 0; i <= b; ++i){
        sum2 += c[n+i-1][n-1];
    }
    __int128 ans = sum1* sum2;
    stack<signed> stk;
    while(ans){
        stk.push(ans%10);
        ans/=10;
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
