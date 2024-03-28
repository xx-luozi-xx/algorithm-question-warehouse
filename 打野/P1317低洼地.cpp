#include <bits/stdc++.h>
using namespace std;
vector<int> data(1e5);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int box; cin >> box;
        if(i!=0){
            box == data.back()? NULL: (data.push_back(box),0);
        }
    }
    long long ans = 0;
    for(int i = 1; i < data.size()-1; ++i){
        ans += (data[i-1]>data[i])&&(data[i]<data[i+1]);
    }
    cout << ans;
    return 0;
}