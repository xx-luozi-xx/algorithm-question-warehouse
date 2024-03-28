#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2e5+30;
int n, c;
int info[MAX_SIZE];
int main(){
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> info[i];
    }
    random_shuffle(info, info+n);
    sort(info, info+n);
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans += upper_bound(info, info+n, info[i]+c)-lower_bound(info, info+n, info[i]+c);
    }
    cout << ans;
    return 0;
}