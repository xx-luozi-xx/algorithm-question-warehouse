#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 40;
int n;

int field[MAX_SIZE][MAX_SIZE];

void dfs(int i, int j, int full){
    if(i<0||n+3<i||j<0||n+3<j) return;
    if(field[i][j] != 0) return;
    field[i][j] = full;
    for(int ii = i-1; ii <= i+1; ++ii){
        for(int jj = j-1; jj <= j+1; ++jj){
            if(ii==i||jj==j)
                dfs(ii,jj,full);
        }
    }
    
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> field[i][j];
        }
    }
    dfs(0,0,-1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(field[i][j] == 0){
                dfs(i,j,2);
            }
        }
    }   
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            //cout << field[i][j] << ' ';
            cout << (field[i][j]==-1?0:field[i][j]) << ' ';
        }cout << "\n";
    }
}

