#include <iostream>
using namespace std;

int h[1000+30];

int main(){
    int n, m, k; cin >> n >> m >>k;
    for(int i = 1; i<=m; ++i){
        h[i] = n;
    }
    while(k--){
        int x, y; cin >> x >> y;
        if(h[y]+x > n){
            h[y]--;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(h[j]+i > n){
                printf("*");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
