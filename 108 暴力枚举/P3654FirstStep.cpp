#include <stdio.h>
bool map[105][105]{};
int R, C, K;

int search(int y, int x){
    int ret = 0;
    //row
    if(x + K-1 < C){
        bool rc = true;
        for(int i = x; i < x+K; ++i){
            if(map[y][i] == 1){
                rc = false;
            }
        }
        ret += rc;
    }
    //cow
    if(y + K-1 < R){
        bool rc = true;
        for(int i = y; i < y+K; ++i){
            if(map[i][x] == 1){
                rc = false;
            }
        }
        ret += rc;
    }
    return ret;
}

int main(){
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0; i < R; ++i){
        scanf("\n");
        for(int j = 0; j < C; ++j){
            char input_c;
            scanf("%c", &input_c);
            if(input_c == '#'){
                map[i][j] = true;
            }
        }
    }
    int out = 0;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            out += search(i, j);
        }
    }
    K==1?out/=2:0;
    printf("%d", out);
    return 0;
}