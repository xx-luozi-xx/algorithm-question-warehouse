#include <bits/stdc++.h>
#define cin std::cin
#define cout std::cout
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;

int n, m;

int info[MAX_N];
int asum[MAX_N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
        asum[i] = asum[i-1] + info[i];
    }
    cin >> m;
    for(int i = 1; i <= m; ++i){
        int l, r; cin >> l >> r;
        cout << asum[r] - asum[l-1] << '\n'; 
    }
    return 0;
}