#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
int n, q;

map<int, int> mp[MAX_SIZE];

int main(){
    cin >> n >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i, j ,k;
            cin >> i >> j >> k;
            mp[i][j] = k;
        }else if(op == 2){
            int i, j;
            cin >> i >> j;
            cout << mp[i][j] << '\n';
        }
    }
    return 0;
}