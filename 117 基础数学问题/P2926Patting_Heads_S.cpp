#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e6+30;


int n;
int info[MAX_SIZE];
int max_info = 0;
int num[MAX_SIZE];
int ans[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
        num[info[i]]++;
        max_info = max(info[i], max_info);
    }

    for(int i = 1; i <= max_info; ++i){
        if(num[i]){
            for(int j = i; j <= max_info; j+=i){
                ans[j]+=num[i];
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << ans[info[i]]-1 << '\n';
    }

    return 0;
}
