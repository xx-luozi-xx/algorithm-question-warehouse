#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
int n;
string a[MAX_N];
string s = "yizhong";

bitset<MAX_N> is[MAX_N];

int drc[8][2] = {
    {0,-1},
    {0,1},
    {1,-1},
    {1,1},
    {1,0},
    {-1,-1},
    {-1,1},
    {-1,0},
};

void dooo(int x, int y){
    for(int i = 0; i < 8; ++i){
        int yes = 1;
        for(int j = 0; j < s.size(); ++j){
            if(!( 0<=x+j*drc[i][0] && x+j*drc[i][0] < n &&
                0<=y+j*drc[i][1] && y+j*drc[i][1] < n &&
                a[x+j*drc[i][0]][y+j*drc[i][1]] == s[j] 
                            )){
                yes = 0;
                break;
            }
        }
        if(yes){
            for(int j = 0; j < s.size(); ++j){
                is[x+j*drc[i][0]][y+j*drc[i][1]] = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dooo(i, j);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%c", is[i][j]?a[i][j]:'*');
        }printf("\n");
    }
    return 0;
}


