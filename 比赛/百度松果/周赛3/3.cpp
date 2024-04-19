//贪心，田忌赛马 https://www.matiji.net/exam/brushquestion/25/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE  = 1e5+30;
int n;
int num_a[MAX_SIZE];
int num_b[MAX_SIZE];

int xxd(int* a, int *b){
    int *max_a = a+(n-1), *max_b =b+(n-1);
    int *min_a = a,       *min_b = b; 
    int ret = 0;

    for(int _ = 0; _ < n; ++_){
        if(*max_a > *max_b){
            ret += 2;
            max_a --, max_b --;
        }else if(*min_a > *min_b){
            ret += 2;
            min_a ++, min_b ++;
        }else if(*max_a <= *max_b){//拿min_a和max_b比
            if(*min_a > *max_b){
                ret += 2;
            }else if(*min_a < *max_b){
                void();
            }else{// ==
                ret ++;
            }
            min_a ++, max_b --;
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num_a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> num_b[i];
    }
    sort(num_a, num_a+n);
    sort(num_b, num_b+n);


    cout << xxd(num_a, num_b) << ' ' << 2*n-xxd(num_b, num_a);
    return 0;
}
