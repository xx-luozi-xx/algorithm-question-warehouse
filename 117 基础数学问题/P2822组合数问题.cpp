#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2e3+3;

int T, k;

int c[MAX_SIZE][MAX_SIZE];
int ans[MAX_SIZE][MAX_SIZE];

int main(){
    cin >> T >> k;

    c[0][0] = 1;
    for(int i = 1; i < MAX_SIZE; ++i){
        c[i][0] = 1;
        ans[i][0] = ans[i-1][0];
        for(int j = 1; j <= i; ++j){
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%k;
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            ans[i][j] += (c[i][j] == 0);
        }
        ans[i][i+1] = ans[i][i];
    }

    // for(int i = 0; i <= 10; ++i){
    //     for(int j = 0; j <= 10; ++j){
    //         printf("[%d-%d]%d\t",i, j, c[i][j]);
    //     }printf("\n");
    // }
    // printf("\n");
    // for(int i = 0; i <= 10; ++i){
    //     for(int j = 0; j <= 10; ++j){
    //         printf("[%d-%d]%d\t",i, j, ans[i][j]);
    //     }printf("\n");
    // }
    for(int i = 1; i <= T; ++i){
        int n, m; cin >> n >> m;
        m = min(n, m);
        cout << ans[n][m] << '\n';
    }
    return 0;
}
