#include <iostream>
#include <memory.h>
#define int long long
using namespace std;
const int MAX_SIZE = 1e6+30;
int n, m;
int num[MAX_SIZE];
int sub[MAX_SIZE];

int d[MAX_SIZE];
int s[MAX_SIZE];
int t[MAX_SIZE];

int arr[MAX_SIZE];
bool check(int day){
    memcpy(arr, sub, sizeof(int)*MAX_SIZE);
    for(int i = 1; i <= day; ++i){
        arr[s[i]] -= d[i];
        arr[t[i]+1] += d[i];
    }
    int r = 0;
    for(int i = 1; i <= n; ++i){
        r += arr[i];
        if(r < 0){
            return 0;
        }
    }
    return 1;
}

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    for(int i = 1; i <= n; ++i){
        sub[i] = num[i]-num[i-1];
    }

    for(int i = 1; i <= m; ++i){
        cin >> d[i] >> s[i] >> t[i];
    }
    int l = 1, r = m;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            l = mid+1;
        }else{
            ans = mid;
            r = mid-1;
        }
    }
    if(ans == 0){
        cout << 0;
    }else{
        cout << -1 << '\n' << ans;
    }
    return 0;
}