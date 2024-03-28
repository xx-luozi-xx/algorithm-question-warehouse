#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 1e5+30;

int n,q,V;
int a[MAX_SIZE];

signed main(){
    cin >> n >> q >> V;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < q; ++i){
        int x, y; cin >> x >> y;
        a[x] = y;
    }
    int ans=  0;
    for(int i = 1; i <= n; ++i){
        ans += (a[i]>=V);
    }
    cout << ans;
    return 0;
}
