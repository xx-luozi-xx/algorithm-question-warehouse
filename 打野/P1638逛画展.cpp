#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e6+30;
int n, m;
int info[MAX_SIZE];
int in[MAX_SIZE];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
    }
    int l = 1, r = 0;
    int cnt = 0;
    
    int len = 0x3f3f3f3f;
    int ans_a, ans_b;
    while(r <= n){
        if(cnt < m){
            ++r;
            if(in[info[r]] == 0){
                cnt++;
            }
            in[info[r]]++;
        }else if(cnt == m){
            if(r-l+1 < len){
                len = r-l+1;
                ans_a = l;
                ans_b = r;
            }
            in[info[l]]--;
            if(in[info[l]] == 0){
                cnt--;
            }
            ++l;
        }else if(cnt > m){
            void();
        }
    }
    cout << ans_a << ' ' << ans_b;
    return 0;
}