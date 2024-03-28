#include <iostream>
#define int long long
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int MAX_SIZE = 1e5+30;

class Tree_node{
public: 
    int l, r;
    int val, tag;
    
    inline int mid(){return (l+r)>>1;}

    Tree_node& ls();
    Tree_node& rs();
  
    void push_down();
    void push_up();

    void add(int lp, int rp, int num)noexcept;
    int  sum(int lp, int rp)noexcept;

private:
    int ls_, rs_;
}node[MAX_SIZE*4];
int node_size = 1;

Tree_node& root = node[0];


inline Tree_node& Tree_node::ls(){
    if(ls_ == 0){
        ls_ = node_size++;
        node[ls_].l = l;
        node[ls_].r = mid();
    }
    return node[ls_];
}

inline Tree_node& Tree_node::rs(){
    if(rs_ == 0){
        rs_ = node_size++;
        node[rs_].l = mid()+1;
        node[rs_].r = r;
    }
    return node[rs_];
}

inline void Tree_node::push_down(){
    if(tag){
        val += (r-l+1)*tag;
        if(l != r){
            ls().tag+=tag;
            rs().tag+=tag;
        }
        tag = 0;
    }
}

inline void Tree_node::push_up(){
    push_down();
    if(l!=r){
        ls().push_down();
        rs().push_down();
        val = ls().val + rs().val;
    }
}

void Tree_node::add(int lp, int rp, int num)noexcept{
    push_down();
    if(l == lp and r == rp){
        tag+=num; return;
    }else if(rp <= mid()){
        ls().add(lp, rp, num);
    }else if(mid()+1 <= lp){
        rs().add(lp, rp, num);
    }else{
        ls().add(lp, mid(), num);
        rs().add(mid()+1, rp, num);
    }
    push_up();
}

int Tree_node::sum(int lp, int rp)noexcept{
    push_down();
    if(l == lp and r == rp){
        return val;
    }else if(rp <= mid()){
        return ls().sum(lp, rp);
    }else if(mid()+1 <= lp){
        return rs().sum(lp, rp);
    }else{
        return ls().sum(lp, mid())+rs().sum(mid()+1, rp);
    }
}


signed main(){
    int n, m; cin >> n >> m;
    root.l = 1; root.r = n;
    for(int i = 1; i <= n; ++i){
        int input; cin >> input;
        root.add(i, i, input);
    }
    for(int i = 0; i < m; ++i){
        int op; cin >> op;
        if(op == 1){
            int x, y ,k; cin >> x >> y >> k;
            root.add(x, y, k);
        }else{
            int x, y; cin >> x >> y;
            cout << root.sum(x, y) << '\n';
        }
    }
    return 0;
}


