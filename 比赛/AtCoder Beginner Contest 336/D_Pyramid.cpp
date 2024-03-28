#include <iostream>
using namespace std;
const int MAX_SIZE = 2e5+30;
int n;
int num[MAX_SIZE];
int up[MAX_SIZE];
int down[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }

    for(int i = 1; i <= n; ++i){
        up[i] = min(up[i-1]+1, num[i]);
    }
    for(int i = n; i > 0; --i){
        down[i] = min(down[i+1]+1, num[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, min(up[i], down[i]));
    }
    cout << ans;
    return 0;
}