#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cout.tie(0), cin.tie(0), 0);
const int MAX_M = 1e3;
const int MAX_N = 30;

int n, m;

struct Eage{
    int b;
    int next;
}eage[MAX_M];
int eage_size = 1;
int head[MAX_N];
int d_in[MAX_N];
set<pair<int, int>> has_eage;

inline void eage_add(int a, int b)noexcept{
    eage[eage_size].b = b;
    eage[eage_size].next = head[a];
    head[a] = eage_size ++;
    d_in[b] ++;
    has_eage.insert({a, b});
}

int vit[MAX_N];
int d_in_tmp[MAX_N];
vector<int> topusort;

void make_topu(int now)noexcept{
    if(d_in_tmp[now] != 0 or vit[now]) return;

    topusort.push_back(now);
    vit[now] = 1;

    for(int itr = head[now]; itr != 0; itr = eage[itr].next){
        if(--d_in_tmp[eage[itr].b] == 0){
            make_topu(eage[itr].b);
        }
    }
}

inline int check()noexcept{
    memcpy(d_in_tmp, d_in, sizeof(d_in));
    memset(vit, 0, sizeof(vit));
    topusort.clear();
    for(int i = 1; i <= n; ++i){
        if(!vit[i]){
            make_topu(i);
        }
    }
    if(topusort.size() < n){
        return -1;
    }
    for(int i = 0; i < topusort.size()-1; ++i){
        if(has_eage.count({topusort[i], topusort[i+1]}) == 0){
            return 0;
        }
    }
    return 1;
}   

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        string in; cin >> in;
        in[0] -= ('A'-1);
        in[2] -= ('A'-1);
        eage_add(in[0], in[2]);

        int rc = check();
        if(rc == 1){
            cout << "Sorted sequence determined after ";
            cout << i;
            cout << " relations: ";
            for(int ii = 0; ii < topusort.size(); ++ii){
                cout << char(topusort[ii]+('A'-1));
            }
            cout << '.';
            return 0;
        }else if(rc == -1){
            cout << "Inconsistency found after ";
            cout << i;
            cout << " relations.";
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    return 0;
}