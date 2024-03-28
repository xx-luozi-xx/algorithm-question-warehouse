#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(1e5+30))

int L, N, M;
int data[MAX_SIZE];

bool check(int x){
    if(x==0){return 0;}
    int cnt = 0;
    stack<int> que;
    int last = 0;
    for(int i = N-1; i >= 1; --i){
        que.push(data[i]);
    }
    while(!que.empty()){
        int now = que.top(); que.pop();
        if(now - last > x){
            int added = (now-last)/x;
            added*x+last == now? added--:0;
            cnt += added;
            last += added * x;
            //cnt++;
            //last += x;
            que.push(now);
        }else{
            last = now;
        }
    }
    return cnt <= M;
}

int main(){
    cin >>L>>N>>M;
    for(int i = 0; i < N; ++i){
        scanf("%d", data+i);
    }
    int _min = 1, _max = L;
    while(1){
        int mid = (_min+_max)/2;
        if(check(mid)&&!check(mid-1)){
            printf("%d", mid);
            return 0;
        }else if(!check(mid)){
            _min = mid+1;
        }else{
            _max = mid-1;
        }
    } 
}