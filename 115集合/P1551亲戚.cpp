#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 5000+30;
int n, m, p;

int union_[MAX_SIZE];
inline int union_init()noexcept{
    for(int i = 0; i < MAX_SIZE; ++i){
        union_[i] = i;
    }
    return 0;
}
int union_init_ = union_init();
int u_find(int a)noexcept{
    return union_[a]==a?a:union_[a] = u_find(union_[a]);
}
inline void U(int a, int b)noexcept{
    union_[u_find(a)] = u_find(b);
}

int main(){
    cin >> n >> m >> p;
    while(m--){
        int a, b;
        cin >> a >> b; 
        U(a, b);
    }
    while(p--){
        int a, b; cin >> a >> b;
        if(u_find(a) == u_find(b)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}
