#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 8080;

int n, q;

pair<int, int> info[MAX_N];
int to_sort[MAX_N];
pair<int, int> tmp[MAX_N];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> info[i].first;
        info[i].second = i;
    }
    memcpy(tmp, info, sizeof(info));
    sort(tmp, tmp+n+1);
    for(int i = 1; i <= n; ++i){
        to_sort[tmp[i].second] = i;
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x, v; cin >> x >> v;
            info[x].first = v;
            tmp[to_sort[x]].first = v;
            
            sort(tmp, tmp+n+1);

            for(int i = 1; i <= n; ++i){
                to_sort[tmp[i].second] = i;
            }

        }else if(op == 2){
            int x; cin >> x;
            pair<int, int> target = info[x];
            cout << find(tmp+1, tmp+n+1, target) - (tmp) << '\n';
        }else{
            void();
        }
    }
}