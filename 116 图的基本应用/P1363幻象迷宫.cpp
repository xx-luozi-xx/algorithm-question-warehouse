//以模后坐标为索引，存第一次到达的非模坐标
//深搜，与第一次到达的非模坐标不同则解决
#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),0);
const int MAX_SIZE = 1500+30;

int n, m;
int S_y, S_x;
char info[MAX_SIZE][MAX_SIZE];

int step_x[4]={0,0,1,-1};
int step_y[4]={1,-1,0,0};

bool ans;
map<pair<int, int>, pair<int, int>> mp;//<y, x>

void dfs(int now_y, int now_x)noexcept{
    if(ans == 1) return;
    int o_y = (now_y + (abs(now_y)/n+3)*n)%n;
    int o_x = (now_x + (abs(now_x)/m+3)*m)%m;
    if(info[o_y][o_x] == '#') return;
    
    if(mp.count({o_y, o_x})){
        if(mp[{o_y, o_x}] != pair<int, int>(now_y, now_x)){
            ans = 1;
            return;
        }else{
            return;
        }
    }

    mp.insert({{o_y, o_x},{now_y, now_x}});

    for(int i = 0; i < 4; ++i){
        if(ans == 1) return;
        dfs(now_y + step_y[i], now_x + step_x[i]);
    }
}

inline bool dooo()noexcept{
    ans = 0;
    mp.clear();
    dfs(S_y, S_x);
    return ans;
}

int main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> info[i][j];
                if(info[i][j] == 'S'){
                    S_y = i;
                    S_x = j;
                }
            }            
        }
        if(dooo()){
            cout << "Yes\n"; 
        }else{
            cout << "No\n";
        }
    }
    return 0;
}