#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 450
#define MV 5

int n, m, x, y;
int board[MAX_SIZE][MAX_SIZE];

int main(){
    for(int i = 0; i < MAX_SIZE; ++i){
        for(int j = 0; j < MAX_SIZE; ++j){
            board[i][j] = -1;
        }
    }
    cin >> n >> m >> x >> y;
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(x, y),0));
    while(!que.empty()){
        auto now = que.front(); que.pop();
        if(0<now.first.second&&now.first.second<=m&&
           0<now.first.first &&now.first.first <=n
           &&board[now.first.first][now.first.second]==-1){
            
            board[now.first.first][now.first.second] = now.second;

            que.push(make_pair(make_pair(now.first.first+1, now.first.second+2),now.second+1));
            que.push(make_pair(make_pair(now.first.first+1, now.first.second-2),now.second+1));
            que.push(make_pair(make_pair(now.first.first-1, now.first.second+2),now.second+1));
            que.push(make_pair(make_pair(now.first.first-1, now.first.second-2),now.second+1));
            que.push(make_pair(make_pair(now.first.first+2, now.first.second+1),now.second+1));
            que.push(make_pair(make_pair(now.first.first+2, now.first.second-1),now.second+1));
            que.push(make_pair(make_pair(now.first.first-2, now.first.second+1),now.second+1));
            que.push(make_pair(make_pair(now.first.first-2, now.first.second-1),now.second+1));

        }else{
            NULL;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}