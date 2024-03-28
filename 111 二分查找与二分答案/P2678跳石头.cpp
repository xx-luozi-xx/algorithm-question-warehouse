#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(5e4+30))

int L, N, M;
int data[MAX_SIZE];

bool check(int x){
    int move = 0;
    queue<int> que;
    for(int i = 1; i < N; ++i){
        que.push(data[i]);
    }
    int last = 0;
    while(que.size()!=1){
        int now = que.front(); que.pop();
        if(now-last<x){
            move++;
        }else{
            last = now;
        }
    }
    if(que.front()-last<x){
        if(last){
            move++;
        }else{//只剩头尾，且间距不够
            return false;
        }
    }

    return move <= M;
}

int main(){
    cin >> L >> N >> M;
    for(int i = 1; i <= N; ++i){
        scanf("%d", data+i);
    }
    data[N+1] = L;
    N+=2;

    int _min = 0, _max = L;
    while(1){
        int mid = (_min + _max)/2;
        if(check(mid)&&!check(mid+1)){
            printf("%d", mid);
            return 0;
        }else if(!check(mid)){ //
            _max = mid - 1;
        }else{
            _min = mid + 1;
        }
    }
}