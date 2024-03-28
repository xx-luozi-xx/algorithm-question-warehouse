#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e6+30;

int un[MAX_SIZE];
int ufind(int x)noexcept{
    return un[x] == x? x: un[x] = ufind(un[x]);
}
inline void U(int x1, int x2)noexcept{
    un[ufind(x1)] = ufind(x2);
}

inline void init()noexcept{
    for(register int i = 0; i < MAX_SIZE; ++i){
        un[i] = i;
    }
}

inline void dooo()noexcept{
    int n; cin >> n;
    stack<pair<int, int>> yes;
    stack<pair<int, int>> no;
    map<int, int> to_me;
    for(int i = 1; i <= n; ++i){
        int a, b, e;
        cin >> a >> b >> e;
        if(to_me.count(a)){
            a = to_me[a];
        }else{
            to_me.insert({a, to_me.size()+1});
            a = to_me[a];
        }

        if(to_me.count(b)){
            b = to_me[b];
        }else{
            to_me.insert({b, to_me.size()+1});
            b = to_me[b];
        }

        if(e == 1){
            yes.push({a, b});
        }else{
            no.push({a, b});
        }
    }
    while(!yes.empty()){
        U(yes.top().first, yes.top().second);
        yes.pop();
    }
    while(!no.empty()){
        if(ufind(no.top().first) == ufind(no.top().second)){
            cout << "NO\n";
            return;
        }
        no.pop();
    }
    cout << "YES\n";
    return;
}


int main(){
    int T; cin >> T;
    while(T--){
        init();
        dooo();
    }
    return 0;
}