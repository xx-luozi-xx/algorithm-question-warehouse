#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 2*(2e5+30);
int a[MAX_SIZE];
int b[MAX_SIZE];
int num[MAX_SIZE], num_size;
unordered_map<int, int> to_me;

struct Eage{
    int b;
    int next;
}eage[MAX_SIZE];
int eage_size = 1;
int head[MAX_SIZE];
int d_in[MAX_SIZE];
inline void add_eage(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size++;
    d_in[b]++;
}

int ans = 0;
int killed[MAX_SIZE];
void kill_leaf(int now)noexcept{
    ans++;
    killed[now] = 1;
    d_in[now]--;
    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        if(!killed[eage[itr].b]){
            d_in[eage[itr].b]--;
            if(d_in[eage[itr].b] == 1){
                kill_leaf(eage[itr].b);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        num[num_size++] = a[i];
        num[num_size++] = b[i];
    }
    sort(num, num+num_size);
    num_size = unique(num, num+num_size)-num;
    for(int i = 0; i < num_size; ++i){
        to_me.insert({num[i], i+1});
    }
    for(int i = 0; i < n; ++i){
        a[i] = to_me[a[i]];
        b[i] = to_me[b[i]];
    }
    
    for(int i = 0; i < n ;++i){
        add_eage(a[i], b[i]);
        add_eage(b[i], a[i]);
    }
    for(int i = 1; i <= num_size; ++i){
        if(d_in[i] == 1){
            kill_leaf(i);
        }
    }
    for(int i = 1; i <= num_size; ++i){
        if(d_in[i] >= 2){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
