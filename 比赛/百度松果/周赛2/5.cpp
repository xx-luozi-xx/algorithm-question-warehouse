// 二分
// https://www.matiji.net/exam/brushquestion/22/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
using namespace std;
#define int long long
const int MAX_SIZE = 1e6+30;

int n, m;
int c[MAX_SIZE];

bool check(int cnt){
    int need = 0;
    for(int i = 0; i < n; ++i){
        need += max(0ll, cnt-c[i]);
    }
    return need <= m and need <= cnt;
}

signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    int l = 0, r = 0x3f3f3f3f;
    int ans;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
