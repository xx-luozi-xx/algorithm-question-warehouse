// https://www.luogu.com.cn/problem/P4653
// 三分法
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1e5 + 30;

int n;
double a[MAX_SIZE];
double b[MAX_SIZE];
//pre_sum
double psum_a[MAX_SIZE];
double psum_b[MAX_SIZE];
//sovle min(S_a, S_b) - (N_a, N_b)
inline double f(double S_a, double S_b, int N_a, int N_b){
    return min(S_a, S_b) - (N_a+N_b);
} 

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    sort(a, a+n, greater<double>());
    sort(b, b+n, greater<double>());

    psum_a[0] = a[0];
    psum_b[0] = b[0];
    for(int i = 1; i < n; ++i){
        psum_a[i] = psum_a[i-1]+a[i];
        psum_b[i] = psum_b[i-1]+b[i];
    }      

    double ans = 0;
    for(int i = 0; i < n; ++i){
        double S_a = psum_a[i];
        int N_a = i+1;

        int l = 0, r = n-1;
        double ans_ = 0;
        while(l <= r){
            int p1 = l + (r-l)/3;
            int p2 = r - (r-l)/3;

            if(f(S_a, psum_b[p1], N_a, p1+1) < f(S_a, psum_b[p2], N_a, p2+1)){
                ans_ = max(ans_, f(S_a, psum_b[p2], N_a, p2+1));
                l = p1 + 1;
            }else{
                ans_ = max(ans_, f(S_a, psum_b[p1], N_a, p1+1));
                r = p2 - 1;
            }
        }
        ans = max(ans, ans_);
    }
    printf("%.4lf", ans);
    return 0;
}
