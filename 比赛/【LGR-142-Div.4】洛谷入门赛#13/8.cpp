#include <bits/stdc++.h>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;

int n, m, a, b;
pair<int, int> all[MAX_SIZE]; //<vla, idx>
pair<int, int> she[MAX_SIZE]; //<val, idx>;

signed main(){
    cin >> n >> m >> a >> b;
    for(int i = 0; i <= n; ++i){
        all[i].second = she[i].second = i;
    }
    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= n; ++j){
            //i个人，j首歌
            int a; cin >> a;
            all[j].first+=a;
            if(i == b){
                she[j].first = a;
            }
        }
    }
    sort(all+1, all+1+n, greater<pair<int, int>>());
    sort(she+1, she+1+n, greater<pair<int, int>>());
    int like = she[1].second;
    int have = 0;
    for(int i = 1; i <= m; ++i){
        if(all[i].second == like){
            have = 1; break;
        }
    }
    if(have){
        cout << like << ' ';
        for(int i = 1; i <= m; ++i){
            if(all[i].second == like) continue;
            cout << all[i].second << ' ';
        }
    }else{
        for(int i = 1; i <= m-1; ++i){
            cout << all[i].second << ' ';
        }
        cout << like << ' ';
    }
    return 0;
}