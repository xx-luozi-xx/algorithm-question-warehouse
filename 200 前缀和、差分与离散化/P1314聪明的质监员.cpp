#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 2e5+30;

int n, m, s;
int w[MAX_SIZE], v[MAX_SIZE];
int l[MAX_SIZE], r[MAX_SIZE];

int w_[MAX_SIZE], v_[MAX_SIZE];
int sw[MAX_SIZE], sv[MAX_SIZE];
int y(int W){
    for(int i = 1; i <= n; ++i){
        w_[i] = w[i]>=W;
        v_[i] = w_[i]*v[i];

        sw[i] = sw[i-1]+w_[i];
        sv[i] = sv[i-1]+v_[i];
    }
    int ret = 0;
    for(int i = 1; i <= m; ++i){
        ret += (sw[r[i]]-sw[l[i]-1])*(sv[r[i]]-sv[l[i]-1]);
    }
    return ret;
}

signed main(){
    cin >> n >> m >> s;
    int min_w = 0x3f3f3f3f3f3f3f3f;
    int max_w = 0;
    for(int i = 1; i <= n; ++i){
        cin >> w[i] >> v[i];
        min_w = min(min_w, w[i]);
        max_w = max(max_w, w[i]);
    }
    for(int i = 1; i <= m; ++i){
        cin >> l[i] >> r[i];
    }
    int ans;
    int ans_val = 0x3f3f3f3f3f3f3f3f;
    int ans_l = min_w;
    int ans_r = max_w+1;
    while(ans_l <= ans_r){
        int mid = (ans_l+ans_r)>>1;
        int y_val = y(mid);
        //printf("(W=%d, y=%d, l=%d, r=%d)\n", mid, y_val, ans_l, ans_r);
        if(abs(y_val-s) < ans_val){
            ans_val = abs(y_val-s);
            ans = mid;
        }

        if(y_val > s){
            ans_l = mid+1;
        }else{
            ans_r = mid-1;
        }
    }
    cout << ans_val;
    return 0;
}