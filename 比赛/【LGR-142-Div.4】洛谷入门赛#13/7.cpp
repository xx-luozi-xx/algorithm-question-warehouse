#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 50;

int n, m;
char info[MAX_SIZE][MAX_SIZE];

int step_i[]={0, 1, 1, 1};
int step_j[]={1, 0, 1, -1};
inline int check(int ii, int jj)noexcept{
    //0 no win
    //1 * win
    //2 # win
    if(info[ii][jj] != '*' and info[ii][jj] != '$') return 0;
    

    for(int go = 0; go < 4; ++go){
        int c = info[ii][jj];
        int win = 1;
        for(int tt = 0, i = ii, j = jj; tt < 5; ++tt, i += step_i[go], j += step_j[go]){
            if(i < 1 or n < i or j < 1 or m < j){
                win = 0;
                break;   
            }
            if(info[i][j] != c){
                win = 0;
                break;
            }
        }
        if(win == 1){
            return c == '*'? 1 : 2;
        }
    }
    return 0;
} 


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> (info[i]+1);
    }
    int cnt_x = 0;//*
    int cnt_y = 0;//$
    for(int i = 1; i <= n ;++i){
        for(int j = 1; j <= m; ++j){
            cnt_x += info[i][j]=='*';
            cnt_y += info[i][j]=='$';
 
            int rc = check(i, j);
            if(rc == 1){
                cout << "Pleasing!";
                return 0;
            }else if(rc == 2){
                cout << "zylwins!";
                return 0;
            }
        }
    }

    if((cnt_x + cnt_y)&1){
        cout << "Z";
    }else{
        cout << "W";
    }
    return 0;
}