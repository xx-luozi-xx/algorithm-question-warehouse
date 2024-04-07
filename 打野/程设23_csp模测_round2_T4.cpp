// https://oj.qd.sdu.edu.cn/v2/problemSet/24/problem/0/3

//still wa
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#define int long long
using namespace std;

#define printf luozi

void luozi(...){}


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
        if((r-l)/2 != (rhs.r-rhs.l)/2){
            return (r-l)/2< (rhs.r-rhs.l)/2;
        }
        return l > rhs.l;
    }
    int len()const{
        return r-l-2;
    }
    int dis()const{
        return (l+r)/2-l-1;
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
            Jian ll = to_r[init.lid];
            Jian rr = to_l[init.rid];
            
            Jian b_jian;
            int pos;
            if(big.dis() > ll.len() and big.dis() >= rr.len()){
                //big
                b_jian = big;
                pos = (b_jian.l+b_jian.r)>>1;
            }else{
                que.push(big);
                if(ll.len() >= rr.len()){
                    //ll
                    b_jian = ll;
                    pos = 1;
                }else{
                    //rr
                    b_jian = rr;
                    pos = m;//m
                }
            }

            isgood[b_jian] = 0;

            Jian l_jian = {b_jian.l, pos, b_jian.lid, t.id};
            Jian r_jian = {pos, b_jian.r, t.id, b_jian.rid};

            que.push(l_jian);
            que.push(r_jian);
            isgood[l_jian] = 1;
            isgood[r_jian] = 1;
            
            to_l[l_jian.rid] = l_jian;
            to_r[l_jian.lid] = l_jian;

            to_l[r_jian.rid] = r_jian;
            to_r[r_jian.lid] = r_jian;

            printf("(%d)[%d,%d]->",t.time,b_jian.l, b_jian.r);
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
            printf("(%d)[%d,%d]+[%d,%d]=[%d,%d]\n", t.time, l_jian.l, l_jian.r, r_jian.l, r_jian.r, n_jian.l, n_jian.r);
        }
    }
    return 0;
}