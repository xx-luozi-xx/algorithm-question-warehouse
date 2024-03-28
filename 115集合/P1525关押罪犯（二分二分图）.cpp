#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = (1e5+30)*2;
int n, m;
struct Eage{
    int b;
    int w;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
inline void eage_add(int a, int b, int w)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].w = w;
    eage[eage_size].next = head[a];
    head[a] = eage_size ++;
}


int vit[MAX_SIZE];
bool check(int mid)noexcept{
    memset(vit, 0, sizeof(vit));
    for(int i = 1; i <= n; ++i){
        if(vit[i] == 0){
            queue<int> que;
            vit[i] = 1;
            que.push(i);
            
            while(!que.empty()){
                int now = que.front();
                que.pop();
                for(int itr = head[now]; itr != 0; itr = eage[itr].next){
                    if(eage[itr].w < mid) continue;

                    int b = eage[itr].b;
                    if(vit[now] == vit[b]){
                        return false;
                    }else{
                        if(vit[b] == 0){
                            vit[b] = vit[now] == 1? 2 : 1;
                            que.push(b);
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    set<int> st;
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        eage_add(a, b, w);
        eage_add(b, a, w);
        st.insert(w);
    }

    int l = 0;
    int r = *st.rbegin();
    int ans = r;

    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    

    if(ans == 0){
        cout << 0;
    }else{
        cout << ans - 1;
    }
    return 0;
}
