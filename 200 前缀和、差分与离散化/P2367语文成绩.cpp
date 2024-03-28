#include <iostream>
using namespace std;
#define cin ::cin
#define cout ::cout

const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 5e6+30;

int n, p;

int info[MAX_N];
int asub[MAX_N];

int main(){
    cin >> n >> p;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
        asub[i] = info[i] - info[i-1];
    }

    for(int i = 1; i <= p; ++i){
        int l, r, score;
        cin >> l >> r >> score;
        asub[l] += score;
        asub[r+1] -= score;
    }

    int ans = 0x3f3f3f3f;
    int asum = 0;
    for(int i = 1; i <= n; ++i){
        asum += asub[i];
        ans = min(asum, ans);
    }
    cout << ans;
    return 0;
}