#include <bits/stdc++.h>
using namespace std;
int n;
double dp[1ll<<17][17];
pair<double, double> xy[17];

inline double dis(int a, int b){
    return sqrt(
    (xy[a].first-xy[b].first)*(xy[a].first-xy[b].first)+
    (xy[a].second-xy[b].second)*(xy[a].second-xy[b].second)
    );
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%lf %lf", &xy[i].first, &xy[i].second);
    }

    for(long long i = 1; i < 1ll<<n; ++i){
        long long state = i;
        for(int j = 1; j <= n; ++j){//第j位能不能翻掉
            long long j_bit = (1ll<<(j-1));
            if( j_bit & state ){
                long long from = state^j_bit;
                if(from){
                    //todo bug
                    double min_ = 1e19;
                    for(int k = 1; k <= n; ++k){
                        long long k_bit = (1ll << (k-1));
                        if(k_bit & from){
                            min_ = min(dp[from][k] + dis(k, j), min_);
                        }
                    }
                    dp[state][j] = min_;
                    //printf("[%d-%d=%lf]\n",state, j, min_);
                    //todo end_bug
                }else{
                    dp[state][j] = dis(0,j);
                    //printf("[%d-%d=%lf]\n",state, j, dis(0, j));
                }
            }
        }        
    }
    double min_ = 1e19;
    for(int i = 1; i <= n; ++i){
        min_ = min(dp[(1ll<<n)-1][i], min_);
    }
    printf("%.2lf", min_);
    return 0;
}