//! https://leetcode.cn/contest/weekly-contest-380
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> sub_str(const string& a, const  string& b){
        vector<int> ret;
        int* nxxt = new int[500030]{};
        int k = 0;
        for(int i = 1; i < b.size(); ++i){
            while(k > 0 and b[i]!=b[k]){
                k = nxxt[k-1];
            }
            if(b[i]==b[k]){
                ++k;
            }
            nxxt[i] = k;
        }

        k = 0;
        for(int i = 0; i < a.size(); ++i){
            while(k > 0 and a[i]!=b[k]){
                k = nxxt[k-1];
            }
            if(a[i] == b[k]){
                ++k;
            }
            if(k == b.size()){
                ret.push_back(i-k+1);
            }
        }
        delete[] nxxt;
        return ret;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> va = sub_str(s, a);//for(int i = 0; i < va.size(); ++i) cout << va[i] << ' ';cout << '\n';
        vector<int> vb = sub_str(s, b);//for(int i = 0; i < va.size(); ++i) cout << vb[i] << ' ';cout << '\n';
        vector<int> ret;
        for(int i = 0; i < va.size(); ++i){
            int l = 0;
            int r = int(vb.size())-1;
            while(l <= r){
                int mid = (l+r)>>1;
                if(abs(va[i]-vb[mid]) <= k){
                    ret.push_back(va[i]);
                    break;
                }    
                if(va[i] < vb[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    //auto x = s.beautifulIndices("diive","viw", "lqqdn", 4);
    auto x = s.beautifulIndices("isawsquirrelnearmysquirrelhouseohmy","my", "squirrel", 15);
    for(int i = 0; i < x.size(); ++i){
        cout << x[i] << ' ';
    }
    return 0;
}