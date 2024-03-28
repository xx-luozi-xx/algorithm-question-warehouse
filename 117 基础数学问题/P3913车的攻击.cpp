#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e6+30;
int N, K;
int col[MAX_SIZE];
int row[MAX_SIZE];

int main(){
    cin >> N  >> K;
    for(int i = 0; i < K; ++i){
        cin >> row[i] >> col[i];        
    }
    sort(col, col+K);
    size_t col_size = unique(col, col+K)-col;
    sort(row, row+K);
    size_t row_size = unique(row, row+K)-row;
    cout << N*(row_size+col_size)-row_size*col_size;
    return 0;
}