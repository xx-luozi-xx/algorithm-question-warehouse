#include <iostream>
#include <tuple>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int INF = 1e6+10;
const int MAX_N = 1e4+10;

int n;
int num[MAX_N];
int cnt[INF];

pair<int, int> mp[INF];//num, times
int mp_size = 0;

signed main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }
    for(int i = 1; i*i <= INF; ++i){
        for(int j = 0; j < n; ++j){
            if(num[j]%i == 0){
                cnt[i] ++;
                if((num[j]/i)*(num[j]/i)>INF){
                    cnt[num[j]/i] ++;
                }
            }
        }
    }
    for(int i = 0; i < INF; ++i){
        if(cnt[i] != 0){
            mp[mp_size++]={i, cnt[i]};
        }
    }
    for(int i = 1; i <= n; ++i){
        int val = 0;
        for(int j = 0; j < mp_size; ++j){
            if(mp[j].second >= i){
                val = max(val, mp[j].first);
            }
        }
        cout << val << '\n';
    }
    return 0;
}




