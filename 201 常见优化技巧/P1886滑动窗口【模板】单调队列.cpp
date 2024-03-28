#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6+30;

int n, k;

int info[MAX_N];

list<int> out;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; cin >> info[i++]);
    deque<pair<int, int>> que_max, que_min;
    for(int i = 1; i <= n; ++i){
        while(!que_max.empty() and que_max.front().second<=i-k){
            que_max.pop_front();
        }
        while(!que_max.empty() and que_max.back().first <= info[i]){
            que_max.pop_back();
        }
        que_max.push_back({info[i], i});
        if(i >= k){
            out.push_back(que_max.front().first);
        }

        while(!que_min.empty() and que_min.front().second<=i-k){
            que_min.pop_front();
        }
        while(!que_min.empty() and que_min.back().first >= info[i]){
            que_min.pop_back();
        }
        que_min.push_back({info[i], i});
        if(i >= k){
            cout << que_min.front().first << ' ';
        }
    }
    cout << '\n';
    for(auto itr = out.begin(); itr != out.end(); ++itr){
        cout << *itr << ' ';
    }
    return 0;
}