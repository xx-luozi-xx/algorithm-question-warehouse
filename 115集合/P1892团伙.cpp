#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5;

int un[MAX_SIZE];
inline int un_init()noexcept{
    for(register int i = 0; i < MAX_SIZE; ++i){
        un[i] = i;
    }
    return 0;
}
int un_init_ = un_init(); 
int ufind(int x)noexcept{
    return un[x]==x?x:un[x]=ufind(un[x]);
}
inline void U(int x1, int x2)noexcept{
    un[ufind(x1)] = ufind(x2);
}

int ener[MAX_SIZE];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        char op; cin >> op;
        int x1, x2; cin >> x1 >> x2;
        if(op == 'E'){
            if(ener[x1]){
                U(ener[x1], x2);
            }else{
                ener[x1] = x2;
            }

            if(ener[x2]){
                U(x1, ener[x2]);
            }else{
                ener[x2] = x1;
            }
        }else if(op == 'F'){
            U(x1, x2);
        }else{
            throw "op err";
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += i==un[i];
    }
    cout << ans;
    return 0;
}