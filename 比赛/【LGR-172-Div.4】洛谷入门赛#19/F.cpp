#include <iostream>
using namespace std;
const int MAX_SIZE = 105;
int n, m, k;
char img[MAX_SIZE][MAX_SIZE];
char out[MAX_SIZE*10][MAX_SIZE*10];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> img[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(int ki = i*k; ki < i*k+k; ++ki){
                for(int kj = j*k; kj < j*k+k; ++kj){
                    out[ki][kj] = img[i][j];
                }
            }
        }
    }
    for(int i = 0; i < n*k; ++i){
        for(int j = 0; j < m*k; ++j){
            cout << out[i][j];
        }
        cout << '\n';
    }
    return 0;
}

