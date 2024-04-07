// https://oj.qd.sdu.edu.cn/v2/problemSet/24/problem/0/3
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#define int long long
using namespace std;

enum Task_Type{
    START, FINISHED
};

struct Task{
    int id;
    int time;
    Task_Type type;
    bool operator<(const Task& rhs)const{
        if(time != rhs.time){
            return time < rhs.time;
        }
        return type == FINISHED;
    }
};

vector<Task> tasks;

struct Jian{
    int l, r;
    int lid, rid;
    bool operator<(const Jian& rhs)const {
        if(r-l != rhs.r-rhs.l){
            return r-l < rhs.r-rhs.l;
        }
        return l > rhs.l;
    }
};

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int start_time, keeping_time;
        cin >> start_time >> keeping_time;
        tasks.push_back({start_time, start_time, START});
        tasks.push_back({start_time, start_time+keeping_time, FINISHED});
    }
    sort(tasks.begin(), tasks.end());
    
    priority_queue<Jian> que;
    map<Jian, int> isgood;
    map<int, Jian> to_l;
    map<int, Jian> to_r;

    Jian init = {0, m+1, -1, -2};

    que.push(init);
    isgood[init] = 1;
    to_l[init.rid] = init;
    to_r[init.lid] = init;

    for(auto t : tasks){
        if(t.type == START){
            Jian big;
            do{
                big = que.top(); que.pop();
            }while(isgood[big] == 0);

            int pos;
            if(big.lid == init.lid){
                pos = 1;//1
            }else if(big.rid == init.rid){
                pos = m;//m
            }else{
                pos = (big.l+big.r)>>1;
            }

            isgood[big] = 0;

            Jian l_jian = {big.l, pos, big.lid, t.id};
            Jian r_jian = {pos, big.r, t.id, big.rid};

            que.push(l_jian);
            que.push(r_jian);
            isgood[l_jian] = 1;
            isgood[r_jian] = 1;
            
            to_l[l_jian.rid] = l_jian;
            to_r[l_jian.lid] = l_jian;

            to_l[r_jian.rid] = r_jian;
            to_r[r_jian.lid] = r_jian;

            cout << pos << '\n';
        }else{
            Jian l_jian = to_l[t.id];
            Jian r_jian = to_r[t.id];
            isgood[l_jian] = 0;
            isgood[r_jian] = 0;

            Jian n_jian = {l_jian.l, r_jian.r, l_jian.lid, r_jian.rid};
            que.push(n_jian);
            isgood[n_jian] = 1;
            to_l[n_jian.rid] = n_jian;
            to_r[n_jian.lid] = n_jian;
        }
    }
    return 0;
}