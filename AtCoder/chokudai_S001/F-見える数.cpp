#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;
int n;
int num[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    int ans = 0;
    int max_ = -0x3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        if(num[i] > max_){
            ans++;
        }
        max_ = max(num[i], max_);
    }
    cout << ans;
    return 0;
}