// https://www.luogu.com.cn/problem/P1578
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define int long long
using namespace std;
const int MAX_SIZE = 3e5+30;


int L, W;
int n;
pair<int, int> points[MAX_SIZE];

signed main(){
    cin >> L >> W;
    cin >> n;
    if(n == 0){
        cout << L*W;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points+n, [](pair<int, int> lhs, pair<int, int>rhs)->bool {
        if(lhs.first != rhs.first){
            return lhs.first < rhs.first;
        }else{
            return lhs.second < rhs.second;
        }
    });

    int ans = 0;
    for(int i = 0; i < n-1; ++i){
        int up = W;
        int low = 0;
        int y = points[i].second;
        for(int j = i+1; j < n; ++j){
            if(points[j].first == points[i].first){
                continue;
            }
            int S = (points[j].first-points[i].first)*(up - low);
            ans = max(ans, S);
            if(points[j].second > y){
                up = min(up, points[j].second);
            }else if(points[j].second < y){
                low = max(low, points[j].second);
            }else{
                up = low = points[j].second;
                break;
            }
        }
        int S = (L-points[i].first)*(up - low);
        ans = max(ans, S);
    }

    for(int i = n-1; i >= 1; --i){
        int up = W;
        int low = 0;
        int y = points[i].second;
        for(int j = i-1; j >= 0; --j){
            if(points[j].first == points[i].first){
                continue;
            }
            int S = abs(points[j].first-points[i].first)*(up - low);
            ans = max(ans, S);
            if(points[j].second > y){
                up = min(up, points[j].second);
            }else if(points[j].second < y){
                low = max(low, points[j].second);
            }else{
                up = low = points[j].second;
                break;
            }
        }
        int S = (points[i].first)*(up - low);
        ans = max(ans, S);
    }

    sort(points, points+n, [](pair<int, int> lhs, pair<int, int>rhs)->bool {
        if(lhs.second != rhs.second){
            return lhs.second < rhs.second;
        }else{
            return lhs.first < rhs.first;
        }
    });

    int max_dy = points[0].second;
    for(int i = 1; i < n; ++i){
        max_dy = max(max_dy, points[i].second - points[i-1].second);
    }
    max_dy = max(max_dy, W-points[n-1].second);
    ans = max(ans, max_dy*L);

    cout << ans;
    return 0;
}