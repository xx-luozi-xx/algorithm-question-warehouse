#include <iostream>
using namespace std;
const int MAX_SIZE = 1000+30;
int yes[MAX_SIZE][4];
int me[MAX_SIZE][4];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 4; ++j){
            cin>>yes[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 4; ++j){
            cin>>me[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        int ans = 0;
        for(int j = 0; j < n; ++j){
            int macht = 0;
            int wrone = 0;
            int getp = 0;
            for(int k = 0; k < 4; ++k){
                if(me[j][k]==yes[(i+j)%n][k]){
                    macht ++;
                    if(me[j][k] == 1){
                        getp++;
                    }
                }else{
                    if(yes[(i+j)%n][k] == 0){
                        wrone++;
                    }
                }
            }
            if(macht==4){
                ans += 6;
            }else if(wrone == 0 and getp > 0){
                ans += 3;
            }
        }
        cout << ans << ' ';
    }


}