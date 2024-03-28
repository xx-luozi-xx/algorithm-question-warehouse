#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;
#define int long long

int n, m;

int A[MAX_SIZE];
int B[MAX_SIZE];
int C[MAX_SIZE];

int from[MAX_SIZE];
int to[MAX_SIZE];

int path[MAX_SIZE];

int asub[MAX_SIZE];
int acnt[MAX_SIZE];

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> path[i];
    }
    for(int i = 1; i <= m-1; ++i){
        from[i] = min(path[i], path[i+1]);
        to[i] = max(path[i], path[i+1]);
    }
    for(int i = 1; i <= n-1; ++i){
        cin >> A[i] >> B[i] >> C[i];
    }

    for(int i = 1; i <= m-1; ++i){
        asub[from[i]]++;
        asub[to[i]]--;
    }

    for(int i = 1; i <= n-1; ++i){
        acnt[i] = acnt[i-1] + asub[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n-1; ++i){
        ans += min(acnt[i]*A[i], acnt[i]*B[i]+C[i]);
    }
    cout << ans;
    return 0;
}