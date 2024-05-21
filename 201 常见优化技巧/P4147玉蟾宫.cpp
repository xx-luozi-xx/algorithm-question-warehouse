//单调栈
// https://www.luogu.com.cn/problem/P4147
#include <iostream>
#include <stack>
using namespace std;
const int MAX_SIZE = 1000+30;
int board[MAX_SIZE][MAX_SIZE];
int down[MAX_SIZE][MAX_SIZE];
int l[MAX_SIZE][MAX_SIZE];
int r[MAX_SIZE][MAX_SIZE];

int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char input; cin >> input;
            board[i][j] = (input == 'F');
            if(board[i][j] == 1){
                down[i][j] = down[i-1][j]+1;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        stack<pair<int, int>> stk;// <num, idx>
        stk.push({-1, 0});
        for(int j = 1; j <= m; ++j){
            while(stk.top().first >= down[i][j]){
                stk.pop();
            }
            l[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }
        stk = stack<pair<int, int>>();// <num, idx>
        stk.push({-1, m+1});
        for(int j = m; j >= 1; --j){
            while(stk.top().first >= down[i][j]){
                stk.pop();
            }
            r[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int val = (r[i][j]-l[i][j]-1)*down[i][j];
            ans = max(ans, val);
        }
    }
    cout << ans*3;
    return 0;
}