//! https://leetcode.cn/contest/weekly-contest-380
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sub_str(const string& a, const  string& b){
        vector<int> ret;
        for(int i = 0; i <= int(a.size())-int(b.size()); ++i){
            bool yes = 1;
            for(int j = 0; j < b.size(); ++j){
                if(a[i+j] != b[j]){
                    yes = 0;
                    break;
                }
            }
            if(yes){
                ret.push_back(i);
            }
        }
        return ret;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> va = sub_str(s, a);
        vector<int> vb = sub_str(s, b);
        vector<int> ret;
        for(int i = 0; i < va.size(); ++i){
            for(int j = 0; j < vb.size(); ++j){
                if(abs(va[i]-vb[j]) <= k){
                    ret.push_back(va[i]);
                    break;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    auto x = s.beautifulIndices("wl","xjigt","wl",2);
    for(int i = 0; i < x.size(); ++i){
        cout << x[i] << ' ';
    }
    return 0;
}