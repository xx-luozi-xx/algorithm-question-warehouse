#include <bits/stdc++.h>
using namespace std;
int n, m;
char out[1600][4096];
char tree[1<<12];

int X_MAX = 1;

void make_tree(int now, int deep)noexcept{
    if(deep == 0) return;
    tree[now] = 1;
    make_tree(now*2+1, deep-1);
    make_tree(now*2, deep-1);
}
inline int tree_idx(int row, int col)noexcept{
    int ret = 1<<(row-1);
    ret += (col-1);
    return ret;
}

int high[15];
inline void make_high()noexcept{
    high[n] = 1;
    if(n-1 < 1) return;
    high[n-1] = 3;
    for(int i = n-2; i >= 1; --i){
        high[i] = high[i+1]*2;
    }
}

struct Point{
    int y,x;
    Point(int y = 0, int x = 0):y(y), x(x){}
};
unordered_map<int, Point> to_yx;
void make_to_yx(int t_idx, int deep)noexcept{
    if(deep > n) return;
    if(t_idx == 1){
        to_yx.insert({t_idx,Point(high[deep], high[deep])});
    }else{
        Point fa = to_yx[t_idx/2];
        if(t_idx & 1){//r
            X_MAX = max(X_MAX, fa.x+(fa.y-high[deep]));
            to_yx.insert({t_idx,Point(high[deep], fa.x+(fa.y-high[deep]))});
        }else{//l
            to_yx.insert({t_idx,Point(high[deep], fa.x-(fa.y-high[deep]))});
        }
    }

    make_to_yx(t_idx*2, deep+1);
    make_to_yx(t_idx*2+1, deep+1);
}

void del(int now)noexcept{
    if(tree[now] == 0) return;
    tree[now] = 0;
    del(now*2);
    del(now*2+1);
}

inline void drow_eage(Point be, Point ed, char c)noexcept{
    int x_go;
    if(c == '/') x_go = 1;
    if(c == '\\') x_go = -1;
    int y = be.y+1;
    int x = be.x + x_go;
    for(int i = be.y+1; i < ed.y; ++i){
        out[y][x] = c;

        y++;
        x+=x_go;
    }
}

void dfs(int now, int deep)noexcept{
    if(deep > n) return;
    if(tree[now] == 0) return;
    Point yx = to_yx[now];
    out[yx.y][yx.x] = 'o';
    if(now != 1){
        drow_eage(to_yx[now], to_yx[now/2], now&1?'\\':'/');
    }
    
    dfs(now*2, deep+1);
    dfs(now*2+1, deep+1);
}


int main(){
    cin >> n >> m;
    if(n == 0) return 0;
    make_tree(1, n);
    make_high();
    make_to_yx(1, 1);

    // for(int i = 1; i < 16; ++i){
    //     printf("[%d->(%d, %d)]\n", i, to_yx[i].y, to_yx[i].x);
    // }

    for(int i = 1; i <= m; ++i){
        int row, col;
        cin >> row >> col;
        del(tree_idx(row, col));
    }
    
    dfs(1, 1);
    //drow point
    for(int i = high[1]; i > 0; --i){
        for(int j = 1; j <= X_MAX; ++j){
            cout << char(out[i][j]?out[i][j]:' ');
        }
        cout << '\n';
    }
    return 0;
}