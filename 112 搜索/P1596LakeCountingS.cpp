#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100+10;
int N, M;
char field[MAX_SIZE][MAX_SIZE];

int unin[MAX_SIZE*MAX_SIZE];

int find(int a){
    if(a == unin[a]) return a;
    return unin[a] = find(unin[a]);    
}

inline void U(int a, int b){
    unin[find(a)] = find(b);
}

inline int idx(int I, int J){
    return I*M + J;
}

int main(){

    for(int i = 0; i < MAX_SIZE*MAX_SIZE; ++i){
        unin[i]=i;
    }

    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> field[i][j];
        }
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(field[i][j] == 'W')
            for(int ii = i-1; ii <= i+1; ++ii){
                for(int jj = j-1; jj <= j+1; ++jj){
                    if(field[ii][jj] == 'W'){
                        U(idx(i,j), idx(ii, jj));
                    }
                }
            }
        }
    }
    set<int> set_;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(field[i][j] == 'W'){
                set_.insert(find(idx(i, j)));
            }
        }
    }

    cout << set_.size();
    return 0;
}