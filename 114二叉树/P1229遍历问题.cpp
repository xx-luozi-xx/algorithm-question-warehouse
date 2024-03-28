#include <bits/stdc++.h>
using namespace std;
string s1, s2;
long long ans = 1;

void dfs(int s1_l, int s1_r, int s2_l, int s2_r){
    s1_l ++; s2_r --;
    if(s1_l > s1_r) return ;
    if(s1[s1_l] == s2[s2_r]){
        ans <<= 1;
        dfs(s1_l, s1_r, s2_l, s2_r);
    }else{
        int s1_a; int s2_a;
        for(int i = s2_l; i <= s2_r; ++i){
            if(s2[i] == s1[s1_l]){
                s2_a = i;
                break;
            }
        }
        for(int i = s1_l; i <= s1_r; ++i){
            if(s1[i] == s2[s2_r]){
                s1_a = i;
                break;
            }
        }
        dfs(s1_l, s1_a-1, s2_l, s2_a);
        dfs(s1_a, s1_r, s2_a+1, s2_r);
    }
}

int main(){
    cin >> s1 >> s2;
    dfs(0, s1.size()-1, 0, s2.size()-1);
    cout << ans;
    return 0;
}