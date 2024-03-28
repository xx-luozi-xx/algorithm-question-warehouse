#include <stdio.h>
#include <math.h>
char map[2000][2000]{{'/','_','_','\\'},{' ','/','\\',' '}};
int main(){
    int n; scanf("%d", &n);
    for(int k = 2; k <= n; ++k){
        const int I_MAX = pow(2,k-1);
        const int J_MAX = 2*I_MAX;
        for(int i = 0; i < I_MAX; ++i){
            for(int j = 0; j < J_MAX; ++j){
                map[i+I_MAX][j+I_MAX] = map[i][j+J_MAX] = map[i][j];
            }
        }
    }
    //* print
    const int I_MAX = pow(2,n);
    const int J_MAX = 2*I_MAX;
    for(int i = I_MAX-1; i >= 0 ; --i){
        for(int j = 0; j < J_MAX; ++j){
            putchar(map[i][j]?map[i][j]:' ');
        }
        putchar('\n');
    }
    return 0;
}