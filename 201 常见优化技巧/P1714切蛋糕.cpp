#include <iostream>
#include <deque>
#include <tuple>

using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 5e5+30;

int n, m;
int num[MAX_SIZE];
int asum[MAX_SIZE];

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    for(int i = 1; i <= n; ++i){
        asum[i] = asum[i-1] + num[i];
    }
    deque<pair<int, int>> que;// <val, pos>
    que.push_back({0,0});
    int ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        while(!que.empty() and que.front().second < i-m){
            que.pop_front();
        }
        ans = max(ans, asum[i]-que.front().first);
        while(!que.empty() and que.back().first >= asum[i]){
            que.pop_back();
        }
        que.push_back({asum[i], i});    
    }
    cout << ans;
    return 0;
}