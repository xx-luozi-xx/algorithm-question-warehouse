// 数位贪心
// https://www.matiji.net/exam/brushquestion/19/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 5e5+30;
int n, m;
int num[MAX_SIZE];
int dead[MAX_SIZE];
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    for(int i = 1; i <= n; ++i){
        num[i] ^= num[i-1];
    }
    int ans = 0;
    for(int i = 63; i >= 0; --i){
        int space = 0;
        for(int j = 1; j <= n; ++j){
            if(((num[j]>>i)&1)== 0 and dead[j] == 0){
                space ++;
            }
        }
        if(((num[n]>>i)&1) == 1 or space < m){
            ans |= (1ll << i);
        }else{
            for(int j = 1; j <= n; ++j){
                if((((num[j]>>i)&1) == 1) and dead[j] == 0){
                    dead[j] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}