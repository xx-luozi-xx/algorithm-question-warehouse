#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2e5+30;
struct X{
    int a,b;
}x[MAX_SIZE];

inline int fight(const X& lhs, const X& rhs)noexcept{
    int round_lhs = (lhs.a+rhs.b-1)/rhs.b;
    int round_rhs = (rhs.a+lhs.b-1)/lhs.b;
    if(round_lhs == round_rhs){
        return 0;
    }else if(round_lhs > round_rhs){
        return 1;
    }else if(round_lhs < round_rhs){
        return -1;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i].a >> x[i].b;
    }
    int winner = 0;
    for(int i = 1; i < n; ++i){
        if(fight(x[i], x[winner]) == 1){
            winner = i;
        }
    }
    int win = 1;
    for(int i = 0; i < n; ++i){
        if(i!=winner and fight(x[winner], x[i]) != 1){
            win = 0;
            break;
        }
    }
    if(win){
        winner++;
    }else{
        winner = -1;
    }
    cout << winner;
    return 0;
}