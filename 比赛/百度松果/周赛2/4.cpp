//二分
// https://www.matiji.net/exam/brushquestion/21/3846/4C6668FEB8CFD6520DE73B365B31D1A4

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1e5+30;
int L, n, k;
int pos[MAX_SIZE];

bool check(int distance){
    int need = 0;
    for(int i = 1; i < n; ++i){
        int dis = pos[i]-pos[i-1];
        need += (dis+distance-1)/(distance) - 1;
    }
    return need <= k;
}

int main(){
    cin >> L >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> pos[i];
    }    
    sort(pos, pos+n);
    int l = 1, r = 0x3f3f3f3f;
    int ans;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}


