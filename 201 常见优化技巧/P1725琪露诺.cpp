#include <queue>
#include <iostream>
using namespace std;
const int MAX_SIZE = 4e5+30;

int N, L, R;
int num[MAX_SIZE];
int dp[MAX_SIZE];

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i <= N; ++i){
        cin >> num[i];
    }
    priority_queue<pair<int, int>> que; // <sum, idx>
    que.push({0, 0});
    for(int i = 0; i <= 2*N+1; ++i){//[i-R, i-L]
        dp[i] = -0x3f3f3f3f;
        if(i-L >= 0){
            que.push({dp[i-L], i-L});
        }
        while(que.top().second<i-R){
            que.pop();
        }
        if(que.top().second <= i-L){
            dp[i] = num[i]+que.top().first;
        }
    }
    cout << dp[2*N];
    return 0;
}