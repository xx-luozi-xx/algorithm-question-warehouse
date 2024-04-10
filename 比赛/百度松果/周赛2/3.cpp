// 二分模板
// https://www.matiji.net/exam/brushquestion/20/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
#include <memory.h>
using namespace std;
const int MAX_SIZE = 1e4+30;
int t, k;

int tasks[MAX_SIZE];
int l[MAX_SIZE];
int r[MAX_SIZE];

int ans_l[MAX_SIZE];
int ans_r[MAX_SIZE];

bool check(int up){
    memset(l, 0, sizeof(int)*MAX_SIZE);
    memset(r, 0, sizeof(int)*MAX_SIZE);
    int begin_task = t;
    for(int people = k; people > 0; --people){
        int all = 0;
        int p = begin_task;
        r[people] = p;
        while(all+tasks[p] < up){
            all += tasks[p];
            l[people] = p;
            p--;
            if(p == 0){
                return 1;
            }
        }
        begin_task = p;
    }
    return 0;
}

int main(){
    cin >> t >> k;
    for(int i = 1; i <= t; ++i){
        cin >> tasks[i];
    }
    int min_ = 0, max_ = 0x3f3f3f3f;
    while(min_ <= max_){
        int mid = (min_ + max_)/2;
        if(check(mid)){
            max_ = mid - 1;
            for(int i = 1; i <= k; ++i){
                ans_l[i] = l[i];
                ans_r[i] = r[i];
            }
        }else{
            min_ = mid + 1;
        }
    }
    for(int i = 1; i <= k; ++i){
        cout << ans_l[i] << ' ' << ans_r[i] << '\n';
    }
    return 0;
}