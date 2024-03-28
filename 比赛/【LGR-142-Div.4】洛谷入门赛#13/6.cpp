#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2e3+30;
int n;
int nxt[MAX_SIZE];
int fa[MAX_SIZE];

int main(){
    cin >> n;
    int ll;
    for(int i = 1; i <= n; ++i){
        int m; cin >> m;
        if(m){
            int a;
            cin >> a;
            nxt[i] = a;
            if(a == -1){
                ll = i;
            }else{
                fa[a] = i;
            }

            for(int i = 1; i <=m-1; ++i){
                cin >> a;
            }
        }else{
            int a;
            cin >> a;
            nxt[i] = a;

            if(a == -1){
                ll = i;
            }else{
                fa[a] = i;
            }
        }
    }
    int head;
    for(int i = ll; 1; i = fa[i]){
        if(fa[i] == 0){
            head = i;
            break;
        }
    }

    for(int i = head; i != -1; i = nxt[i]){
        cout << i << ' ';
    }
    return 0;
}