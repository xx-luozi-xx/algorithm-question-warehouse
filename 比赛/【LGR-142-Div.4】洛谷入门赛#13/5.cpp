#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
int n, x, y, a, b;


int main(){
    cin >> n >> x >> y >> a >> b;
    int you = 0;
    int meiyou = 0;
    unsigned long long ans = 0;
    unsigned long long max_ans = 0;

    for(int i = 0; i < n; ++i){
        int a1, a2, M;
        cin >> a1 >> a2 >> M;
        int m = a1*x + a2*y;
        int M_ = M - m;
        if(M_ == 0){//meiyou
            you = 0;
            meiyou ++;
            if(meiyou >= b){
                ans >>= 1;
            }
        }else{
            meiyou = 0;
            you++;
            ans += M_;
            if(M_ > m){
                ans += (M_+1)/2;
            }
            if(you >= a){
                ans <<= 1;
            }
        }
        max_ans = max(max_ans, ans);
    }
    cout << max_ans << ' ' << ans;
    return 0;
}