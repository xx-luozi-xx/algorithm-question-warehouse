#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);

int main(){
    int T; cin >> T;
    while(T-->0){
        int n; cin >> n;
        vector<int> data;
        for(int i = 0; i < n; ++i){
            int num; cin >> num;
            data.push_back(num);
        }
        unordered_map<int, int> cnt;
        int ans = 0;
        int l = 0, r = 0;
        cnt[data[0]]++;

        while(r<n){
            if(cnt[data[r]] == 1){//good
                ans = max(ans, r-l+1);
                r++;
                cnt[data[r]]++;
            }else{//bad
                cnt[data[l]]--;
                l++;
            }
        }
        cout << ans << '\n';
    }
}