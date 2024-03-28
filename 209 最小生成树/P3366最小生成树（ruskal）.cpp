#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 2e5+30;

int N, M;
struct Eage{
    int a;
    int b;
    int w;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];

vector<Eage> eage_set;

int un[MAX_SIZE];
int un_init_()noexcept{
    for(int i = 0; i < MAX_SIZE; ++i){
        un[i] = i;
    }
    return 0;
}
int un_init = un_init_();
int ufind(int x)noexcept{
    return un[x]==x?x:un[x]=ufind(un[x]);
}
inline void ulink(int x, int y)noexcept{
    un[ufind(y)] = ufind(x);
}

inline void add_eage(int a, int b, int w)noexcept{
    eage[eage_size].a = a;
    eage[eage_size].b = b;
    eage[eage_size].w = w;
    eage[eage_size].next = head[a];
    
    eage_set.push_back(eage[eage_size]);

    head[a] = eage_size++;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        add_eage(a, b ,w);
    }
    sort(eage_set.begin(), eage_set.end(), [](const Eage& lhs, const Eage& rhs)->bool {
        return lhs.w < rhs.w;
    });
    unsigned long long ans = 0;
    unsigned long long cnt = 0;
    for(auto itr = eage_set.begin(); itr != eage_set.end(); ++itr){
        if(ufind(itr->a) != ufind(itr->b)){
            ulink(itr->a, itr->b);
            cnt++;
            ans+= itr->w;
        }
    }
    if(cnt == N-1){
        printf("%llu", ans);
    }else{
        printf("orz");
    }
    return 0;
}

