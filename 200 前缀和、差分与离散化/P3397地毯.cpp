#include <iostream>
using namespace std;
const int MAX_SIZE = 1010;

int n, m;

int asub[MAX_SIZE][MAX_SIZE];
int info[MAX_SIZE][MAX_SIZE];

int main(){
    ::cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int i1, j1, i2, j2;
        ::cin >> i1 >> j1 >> i2 >> j2;
        asub[i1][j1]++;
        asub[i1][j2+1]--;
        asub[i2+1][j1]--;
        asub[i2+1][j2+1]++;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            info[i][j] = asub[i][j] + info[i-1][j] + info[i][j-1] - info[i-1][j-1];
            ::cout << info[i][j] << ' ';
        }
        ::cout << '\n';
    }
    return 0;
}


