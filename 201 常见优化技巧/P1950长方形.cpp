//单调栈
// https://www.luogu.com.cn/problem/P1950
#include <iostream>
#include <stack>
#include <tuple>
using namespace std;
const int MAX_SIZE = 1000+30;

#define printf luozi
void luozi(...){}

int n, m;
int board[MAX_SIZE][MAX_SIZE];
int down[MAX_SIZE][MAX_SIZE];
int l[MAX_SIZE][MAX_SIZE];
int r[MAX_SIZE][MAX_SIZE];

int main(){
    cin >>n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char  input; cin >> input;
            board[i][j] = (input == '.');
            if(board[i][j]){
                down[i][j] = down[i-1][j]+1;
            }
        }
    }


    printf("\n");
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            printf("%d ", down[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; ++i){
        stack<pair<int, int>> stk; //<num, idx>
        stk.push({-1, 0});
        for(int j = 1; j <= m; ++j){
            while(down[i][j] < stk.top().first){
                stk.pop();
            }
            l[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }

        stk  = stack<pair<int, int>>(); //<num, idx>
        stk.push({-1, m+1});
        for(int j = m; j >= 1; --j){
            while(down[i][j] <= stk.top().first){
                stk.pop();
            }
            r[i][j] = stk.top().second;
            stk.push({down[i][j], j});
        }
    }

    printf("\n");
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            printf("%d ", l[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    unsigned long long ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            printf("%d ", (j-l[i][j])*(r[i][j]-j)*down[i][j]);
            ans += (j-l[i][j])*(r[i][j]-j)*down[i][j];
        }
        printf("\n");
    }
    printf("\n");
    cout << ans;
    return 0;
}