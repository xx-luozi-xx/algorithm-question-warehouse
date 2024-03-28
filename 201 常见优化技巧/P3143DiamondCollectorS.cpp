#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 50050;

int n, k;

int info[MAX_N];
int L_ans[MAX_N];
int R_ans[MAX_N];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; cin >> info[i++]);
    sort(info+1, info+n+1);
    queue<int> que;
    for(int i = 1; i <= n; ++i){
        while(!que.empty() and info[i]-que.front()>k){
            que.pop();
        }
        que.push(info[i]);
        L_ans[i] = que.size();
    }
    for(int i = 1; i <= n; ++i){
        L_ans[i] = max(L_ans[i], L_ans[i-1]);
    }
    que = queue<int>();
    for(int i = n; i > 0; --i){
        while(!que.empty() and que.front() - info[i]>k){
            que.pop();
        }
        que.push(info[i]);
        R_ans[i] = que.size();
    }
    for(int i = n; i > 0; --i){
        R_ans[i] = max(R_ans[i], R_ans[i+1]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, L_ans[i]+R_ans[i+1]);
    }
    cout << ans;
    return  0;
}