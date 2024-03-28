#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = (1e5+30)*2;

int udata[MAX_SIZE];
int ufind(int x)noexcept{
    return udata[x] == x ? x : udata[x] = ufind(udata[x]);
}
inline void U(int x, int y)noexcept{
    udata[ufind(x)] = ufind(y); 
}

int n, m;

struct Info{
    int a;
    int b;
    int w;
}info[MAX_SIZE];

struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
inline void add_eage(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
}

int main(){
    for(int i = 0; i < MAX_SIZE; ++i){
        udata[i] = i;
    }
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> info[i].a >> info[i].b >> info[i].w;
    }
    random_shuffle(info, info+m);
    sort(info, info+m, [](const Info& lhs, const Info& rhs){
        return lhs.w > rhs.w;
    });
    for(int i = 0; i < m; ++i){
        int a = info[i].a;
        int b = info[i].b;
        int w = info[i].w;
        if(ufind(a) == ufind(b)){
            cout << w;
            return 0;
        }else{
            add_eage(a, b);
            add_eage(b, a);
            for(int itr = head[a]; itr != 0; itr = eage[itr].next){
                U(b, eage[itr].b);
            }
            for(int itr = head[b]; itr != 0; itr = eage[itr].next){
                U(a, eage[itr].b);
            }
        }
    }
    cout << 0;
    return 0;
}