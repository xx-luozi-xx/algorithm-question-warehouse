#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 300+50;

struct point{
    int x,y;
    point(int x = 0, int y = 0):x(x), y(y){}
    bool operator==(const point&rhs){
        return x==rhs.x && y == rhs.y;
    }
};


point pro[128][2];
int pro_size[128];

char Map[MAX_SIZE][MAX_SIZE];
char visit[MAX_SIZE][MAX_SIZE];

inline char& Map_(point a){
    return Map[a.y][a.x];
}
inline char& vit(point a){
    return visit[a.y][a.x];
}
int N, M;

point Start;
point End;

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> Map[i][j];
            if(Map[i][j] == '='){
                End.y = i;
                End.x = j; 
            }else if(Map[i][j] == '@'){
                Start.y = i;
                Start.x = j;
            }else if('A'<=Map[i][j] && Map[i][j] <= 'Z'){
                pro[Map[i][j]][pro_size[Map[i][j]]].y = i;
                pro[Map[i][j]][pro_size[Map[i][j]]].x = j;
                pro_size[Map[i][j]]++;
            }
        }
    }

    queue<pair<point, int>> que;
    que.push({Start, 0});
    while(!que.empty()){
        point now = que.front().first;
        int step = que.front().second;
        que.pop();

        if(Map_(now) == '='){
            cout << step;
            return 0;
        }
        //printf("{(%d,%d),%d}", now.x, now.y, step);
        //range
        if(now.y<1||N<now.y||now.x<1||M<now.x){
            continue;
        }
        if(vit(now)){
            continue;
        }
        if(Map_(now) == '#'){
            continue;
        }   
        
        vit(now) = 1;
        
        if('A'<=Map_(now) && Map_(now)<= 'Z'){
            if(pro[Map_(now)][0] == now){
                now = pro[Map_(now)][1];
                //vit(now) = 1;
            }else{
                now = pro[Map_(now)][0];
                //vit(now) = 1;
            }
        }

        step++;
        que.push({point(now.x+1, now.y), step});
        que.push({point(now.x, now.y+1), step});
        que.push({point(now.x-1, now.y), step});
        que.push({point(now.x, now.y-1), step});
    }
    printf("-1");
    return 0;
}