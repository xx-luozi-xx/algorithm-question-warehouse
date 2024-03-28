#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 250

int flr[MAX_SIZE];
bitset<MAX_SIZE> vit;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    for(int i = 0; i < N; ++i){
        scanf("%d", flr+i);
    }
    queue<pair<int, int>> que;
    que.push(make_pair(A-1,0));
    while(!que.empty()){
        auto now = que.front(); que.pop();
        if(now.first<0||now.first>=N||vit[now.first]){
            continue;
        }
        if(now.first == B-1){
            cout << now.second;
            return 0;
        }

        vit[now.first] = 1;
        que.push(make_pair(now.first+flr[now.first], now.second+1));
        que.push(make_pair(now.first-flr[now.first], now.second+1));

    }

    cout << -1;
    return 0;


}

