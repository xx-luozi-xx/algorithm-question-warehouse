#include <iostream>
#include <algorithm>

using namespace std;

int n;
int info[(int)1e5];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> info[i];
    }
    sort(info, info+n);
    unsigned long long ans = 1;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(info[i]-cnt > 0){
            ans *= info[i]-cnt;
            ans %= 1000000007;
            cnt ++;
        }else{
            cout << 0;
            return 0;
        }
    }
    cout << ans;
    return 0;
}