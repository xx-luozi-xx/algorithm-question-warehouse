#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1010;

int n, m, c;

int info[MAX_SIZE][MAX_SIZE];
int asum[MAX_SIZE][MAX_SIZE];

int main(){
    cin >> n >> m >> c;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> info[i][j];
            asum[i][j] = info[i][j] + asum[i][j-1] + asum[i-1][j] - asum[i-1][j-1];
        }
    }
    int ans_i, ans_j;
    long long max_ = -0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int ii = i+c-1;
            int jj = j+c-1;
            if(ii>n or jj>m) continue;
            int cost = asum[ii][jj]-asum[ii][j-1]-asum[i-1][jj]+asum[i-1][j-1];
            if(cost > max_){
                max_ = cost;
                ans_i = i;
                ans_j = j;
            }
        }
    }
    cout << ans_i << ' ' << ans_j;
    return 0;
}