#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_SIZE_ = 1e5+30;
int n, m;
string str;
int cnt[MAX_SIZE_][128]{};

int main(){
    cin >> n >> m;
    string tmp;
    cin >> tmp;
    str = "X" + tmp;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 128; ++j){
            cnt[i][j] = cnt[i-1][j];
        }
        cnt[i][str[i]] = cnt[i-1][str[i]]+1;
    }
    for(int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        int max_cnt = 0;

        for(int c = 'a'; c <= 'z'; ++c){
            max_cnt = max(cnt[r][c]-cnt[l-1][c], max_cnt);
        }

        cout << (r-l+1)-max_cnt << '\n';
    }
    return 0;
}