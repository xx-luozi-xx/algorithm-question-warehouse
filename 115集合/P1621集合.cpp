#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;

int isnpri[MAX_SIZE]{1,1,0};
int pri[MAX_SIZE], pri_size = 0;


int un[MAX_SIZE];
int ufind(int x)noexcept{
    return un[x]==x?x:un[x]=ufind(un[x]);
}
inline void U(int x1, int x2)noexcept{
    un[ufind(x1)] = ufind(x2);
}


int main(){
    for(int i = 0; i < MAX_SIZE; ++i){
        un[i] = i;
    }
    int a, b, p;
    cin >> a >> b >> p;
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnpri[i]){
            pri[pri_size++] = i;
        }
        for(int j = 0; j < pri_size and i*pri[j] < MAX_SIZE; ++j){
            isnpri[i*pri[j]] = 1;
            if(i%pri[j] == 0){
                break;
            }
        }
    }
    int p_begin = lower_bound(pri, pri + pri_size, p) - pri;
    for(int i = p_begin; i < pri_size; ++i){
        queue<int> que;
        for(int j = 1; pri[i]*j<=b; ++j){
            que.push(j*pri[i]);
        }
        if(!que.empty()){
            int root = que.front();
            while(!que.empty()){
                U(root, que.front());
                que.pop();
            }
        }
    }

    int ans = 0;
    for(int i = a; i <= b; ++i){
        if(i == un[i]){
            ans ++;
        }
    }
    cout << ans;
}