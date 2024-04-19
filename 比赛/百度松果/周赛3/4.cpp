//st表 二分 https://www.matiji.net/exam/brushquestion/24/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
#include <math.h>
using namespace std;
const int MAX_SIZE = 1e6+30;
const int MAX_LOG = log2(MAX_SIZE)+1;
int log_2[MAX_SIZE];
void init_log(){
    for(int i = 2; i < MAX_SIZE; i*=2){
        log_2[i] = 1;
    }
    for(int i = 2; i < MAX_SIZE; ++i){
        log_2[i] += log_2[i-1];
    }
}

int n;
int a[MAX_SIZE];//max
int b[MAX_SIZE];//min

int st_max[MAX_SIZE][MAX_LOG];
int st_min[MAX_SIZE][MAX_LOG];

inline int find_max(int l, int r){
    int len = r-l+1;
    int log_len = log_2[len];
    return max(st_max[l][log_len], st_max[r-(1<<log_len)+1][log_len]);
}
inline int find_min(int l, int r){
    int len = r-l+1;
    int log_len = log_2[len];
    return min(st_min[l][log_len], st_min[r-(1<<log_len)+1][log_len]);
}

int main(){
    init_log();
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }

    //make st_max
    for(int i = 1; i <= n; ++i){
        st_max[i][0] = a[i];//printf("st_max[i][0]=%d ", a[i]); 
        st_min[i][0] = b[i];
    }//printf("\n");
    for(int i = 1; i < MAX_LOG; ++i){
        for(int j = 1; j <= n and j+(1<<i)-1 <= n; ++j){
            st_max[j][i] = max(st_max[j][i-1], st_max[j+(1<<(i-1))][i-1]);//printf("st_max[%d][%d]=%d ",j, i, st_max[j][i]);
            st_min[j][i] = min(st_min[j][i-1], st_min[j+(1<<(i-1))][i-1]);//printf("st_max[%d][%d]=%d ",j, i, st_max[j][i]);
        }//printf("\n");
    }

    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        int l, r, pos, pos_;
        l = 1, r = i;
        pos = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(find_max(mid, i) >= find_min(mid, i)){//max >= min
                pos = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        l = 1, r = i;
        pos_ = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(find_max(mid, i) > find_min(mid, i)){//max > min
                pos_ = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        int L_cnt = pos-pos_;//printf("L:%d, %d\n", pos_, pos);
        ans += L_cnt;
    }
    cout << ans;
    return 0;
}




