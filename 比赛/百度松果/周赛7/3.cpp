/*
单调栈，最大子矩阵
https://www.matiji.net/exam/dohomework/6418/3
*/
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 1000+30;

int n, m;
char board[MAX_SIZE][MAX_SIZE];
int down[MAX_SIZE][MAX_SIZE];
int l[MAX_SIZE][MAX_SIZE];
int r[MAX_SIZE][MAX_SIZE];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char input; cin >> input;
            board[i][j] = (input == 'G');
            if(board[i][j]){
                down[i][j] = down[i-1][j] + 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        stack<pair<int, int>> stk;//<num, idx>
        stk.push({-1,0});
        for(int j = 1; j <= m; ++j){
            while(stk.top().first >= down[i][j]){
                stk.pop();
            }
            l[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }

        stk = stack<pair<int, int>>();//<num, idx>
        stk.push({-1,m+1});
        for(int j = m; j >= 1; --j){
            while(stk.top().first >= down[i][j]){
                stk.pop();
            }
            r[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            ans = max(ans, (long long)((r[i][j]-l[i][j]-1))*down[i][j]);
        }
    }
    cout << ans*10;
    return 0;
}
