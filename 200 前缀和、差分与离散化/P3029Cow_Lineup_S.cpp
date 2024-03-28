#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAX_SIZE = 5e4+30;

int n;
struct Cow{
    int x; int id;
}cow[MAX_SIZE];

int all_id[MAX_SIZE];
int all_id_size = 0;

bool check(int len){
    unordered_map<int, int> cnt;
    int total = 0;
    queue<Cow> que;
    for(int i = 0; i < n; ++i){
        que.push(cow[i]);
        if(cnt[cow[i].id]++ == 0){
            total ++;
        }
        while(que.back().x - que.front().x + 1 > len){
            if(--cnt[que.front().id] == 0){
                total --;
            }
            que.pop();
        }
        if(total == all_id_size){
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> cow[i].x >> cow[i].id;
        all_id[all_id_size++] = cow[i].id;
    }
    sort(all_id, all_id + all_id_size);
    all_id_size = unique(all_id, all_id+all_id_size)-all_id;

    sort(cow, cow+n,[](Cow lhs, Cow rhs)->bool {
        return lhs.x < rhs.x;
    });

    int l = 1;
    int r = cow[n-1].x-cow[0].x+1;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans-1;
    return 0;
}