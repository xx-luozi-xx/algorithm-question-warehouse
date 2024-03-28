#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50;
int n;

vector<string> arr;
int cnt[MAX_N];
//vector<int> pokt;
int long_ = 0;
int ans = 0;

int conet(int a_, int b_){
    string& a = arr[a_];
    string& b = arr[b_];
    for(int i = 1; i < min(a.size(), b.size()); ++i){
        int _a = a.size()-i;
        int great = 1;
        for(int j = 0; j+_a<a.size(); ++j){
            if(a[_a+j] != b[j]){
                great = 0;
                break;
            }
        }
        if(great){
            return i;
        }
    }
    return 0;
}
void dfs(int idx){
    if(cnt[idx] >= 2) return;

    cnt[idx]++;
    // pokt.emplace_back(idx);
    long_ += arr[idx].size();

    int no_next = 1;
    for(int i = 0; i < n; ++i){
        int xx=conet(idx, i);
        if(cnt[i]<2 && xx){//还能用且能接上
            no_next = 0;
            long_ -= xx;
            dfs(i);
            long_ += xx;
        }
    }

    ans = max(ans, long_);

    cnt[idx]--;
    // pokt.pop_back();
    long_ -= arr[idx].size();
}
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        string x;
        cin >> x;
        arr.emplace_back(x);
    }
    {
        string x;
        cin >> x;
        string _x = "~";
        arr.emplace_back(_x+x);
    }
    
    dfs(n);

    cout << ans-1;
    return 0;
}