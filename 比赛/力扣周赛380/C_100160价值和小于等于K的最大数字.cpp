//! https://leetcode.cn/contest/weekly-contest-380
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long cntt(long long num, int idx){
        return ((num+1)/(1ll<<idx))*(1ll<<(idx-1))+max(0ll,(num+1)%(1ll<<idx)-(1ll<<(idx-1)));
    }
    bool check(long long mid, long long k, int x){
        long long sum = 0;
        for(int i = x; i < 64; i+=x){
            sum += cntt(mid, i);
            if(sum > k) return 0;
        }
        return sum <= k;
    }
    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = 0x3f3f3f3f3f3f3f3f;
        long long ans;
        while(l <= r){
            long long mid = (l+r)>>1;
            if(check(mid, k, x)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<< s.findMaximumNumber(1,9);
}