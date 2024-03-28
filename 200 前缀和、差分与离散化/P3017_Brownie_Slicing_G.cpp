#include <iostream>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 505;

int R,C,A,B;
int num[MAX_SIZE][MAX_SIZE];
int asum[MAX_SIZE][MAX_SIZE];

inline int sum(int i1, int j1, int i2, int j2){
    return asum[i2][j2] 
          -asum[i2][j1-1]
          -asum[i1-1][j2]
          +asum[i1-1][j1-1];
}

bool check(int one)noexcept{
    //todo
    int H1 = 1, H2 = 1;
    int finished_H = 0;
    while(H2 <= R){
        int W1 = 1, W2 = 1;
        int finished_W = 0;
        while(W2 <= C){
            if(sum(H1, W1, H2, W2) >= one){
                finished_W ++;
                W1 = ++W2;
            }else{
                W2 ++;
            }
        }
        if(finished_W >= B){
            finished_H ++;
            H1 = ++H2;
        }else{
            H2 ++;
        }
    }
    return finished_H >= A;
}

int main(){
    cin >> R >> C >> A >> B;
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            asum[i][j] = asum[i][j-1]+asum[i-1][j]-asum[i-1][j-1]+num[i][j];
        }
    }
    int l = 0;
    int r = 0x3f3f3f3f;
    int ans;
    while(l <= r){
        int mid =(l+r)>>1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans;
}



