#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 00);
const int MAX_SIZE = 2e5+30;

int N, M;

struct Eage{
    int a;
    int b;
    int w;
    int next;
}eage[MAX_SIZE*2];
int eage_size = 1;
int head[MAX_SIZE];

int tag[MAX_SIZE];

class Eage_Greater{
public:
    bool operator()(const Eage&lhs, const Eage&rhs){
        return lhs.w > rhs.w;
    }   
};

inline void add_eage(int a, int b, int w)noexcept{
    eage[eage_size].a = a;
    eage[eage_size].b = b;
    eage[eage_size].w = w;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        add_eage(a, b, w);
        add_eage(b, a, w);
    }

    priority_queue<Eage, vector<Eage>, Eage_Greater> que;
    que.push({1,1,0,0});
    unsigned long long ans = 0;
    unsigned long long cnt = 0;
    while(!que.empty()){
        int b = que.top().b;
        int w = que.top().w;
        que.pop();
        if(tag[b] != 0){
            continue;
        }
        cnt++;
        ans+=w;
        tag[b] = 1;
        if(cnt == N){
            break;
        }
        for(int itr = head[b]; itr != 0; itr = eage[itr].next){
            if(tag[eage[itr].b] == 0){
                que.push(eage[itr]);
            }
        }
    }
    if(cnt == N){
        printf("%llu", ans);
    }else{
        printf("orz");
    }
    return 0;
}