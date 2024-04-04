// https://www.matiji.net/exam/brushquestion/17/3846/4C6668FEB8CFD6520DE73B365B31D1A4

#include <iostream>
#include <assert.h>
using namespace std;
const int MAX_SIZE = 1e5+30;
int n;
int num[MAX_SIZE];


int cnt(int l, int r, int cut = 0){
    assert(l <= r);
    // printf("[%d,%d]", l,r);
    int min_val = num[l];
    int max_val = num[l];
    for(int i = l; i <= r; ++i){
        min_val = min(min_val, num[i]); 
        max_val = max(max_val, num[i]); 
    }
    if(min_val == max_val){
        return min(r-l+1, min_val-cut);
    }

    int ans = min_val-cut;
    for(int i = l; i <= r; ++i){
        if(num[i] > min_val){
            int j = i;
            while(j <= r and num[j] > min_val){
                ++j;
            }
            ans += cnt(i, j-1, min_val);
            i = j;
        }
    }
    return min(ans, r-l+1);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    cout << cnt(1, n);
    return 0;
}
