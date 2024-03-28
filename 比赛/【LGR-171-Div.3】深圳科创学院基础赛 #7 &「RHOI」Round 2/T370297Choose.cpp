#include <iostream>
#include <list>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 1e5+30;

int n, k;
int num[MAX_SIZE];

bool check(int the_len, int min_ans){
    int good_time = 0;
    list<pair<int, int>> up, down;//num, idx
    for(int i = 0; i < n; ++i){
        while(!up.empty() and up.front().second <i+1-the_len){
            up.pop_front();
        }
        while(!up.empty() and up.back().first <= num[i]){
            up.pop_back();
        }
        up.push_back({num[i],i});
        int max_val = up.front().first;
        while(!down.empty() and down.front().second< i+1-the_len){
            down.pop_front();
        }
        while(!down.empty() and down.back().first >= num[i]){
            down.pop_back();
        }
        down.push_back({num[i],i});
        int min_val = down.front().first;
        if(i>= the_len-1){
            if(max_val-min_val >= min_ans){
                good_time ++;
            }
        }
    }    
    return good_time >= k;
}

signed main(){
    int T; cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 0; i < n; ++i){
            cin >> num[i];
        }
        int len = n-k+1;
        int min_ans = 0x3f3f3f3f3f3f3f3f;
        list<pair<int, int>> up, down;//num, idx
        for(int i = 0; i < n; ++i){
            while(up.front().second <i+1-len){
                up.pop_front();
            }
            while(!up.empty() and up.back().first <= num[i]){
                up.pop_back();
            }
            up.push_back({num[i],i});
            int max_val = up.front().first;
            while(down.front().second< i+1-len){
                down.pop_front();
            }
            while(!down.empty() and down.back().first >= num[i]){
                down.pop_back();
            }
            down.push_back({num[i],i});
            int min_val = down.front().first;
            if(i>= len-1){
                min_ans = min(min_ans, max_val-min_val);
            }
        }
        int l = 1, r = len;
        int max_len=-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid, min_ans)){
                max_len = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout << min_ans << ' ' << max_len << '\n';
    }
    return 0;
}