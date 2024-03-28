#include <bits/stdc++.h>
using namespace std;
string s1, s2;

void dfs(int s1_l, int s1_r, int s2_l, int s2_r)noexcept{
    if(s1_l <= s1_r){
        cout << s2[s2_r];
        int s1_a;
        for(int i = s1_l; i <= s1_r; ++i){
            if(s1[i] == s2[s2_r]){
                s1_a = i;
                break;
            }
        }
        dfs(s1_l, s1_a-1, s2_l, s2_l+(s1_a-1-s1_l));
        dfs(s1_a+1, s1_r, s2_l+(s1_a-1-s1_l)+1, s2_r-1);
    }
}

int main(){
    cin >> s1 >> s2;
    dfs(0, s1.size()-1, 0, s2.size()-1);
    return 0;
}