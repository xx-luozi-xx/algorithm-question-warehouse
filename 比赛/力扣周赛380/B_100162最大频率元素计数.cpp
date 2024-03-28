//! https://leetcode.cn/contest/weekly-contest-380
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
        }
        int the_max_times = 0;
        for(auto itr = mp.begin(); itr!= mp.end(); ++itr){
            the_max_times = max(the_max_times, itr->second);
        }
        int ret = 0;
        for(auto itr = mp.begin(); itr!= mp.end(); ++itr){
            if(itr->second == the_max_times){
                ret += the_max_times;
            }
        }
        return ret;
    }
};