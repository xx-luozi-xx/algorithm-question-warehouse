    #include <bits/stdc++.h>
    using namespace std;
    #define MAX_MAP 350
    #define MAX_M 50050

    bitset<MAX_MAP> vit[MAX_MAP];
    bitset<MAX_MAP> bad[MAX_MAP];

    int main(){
        int M; cin >> M;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> star;
        for(int i = 0; i < M; ++i){
            int t, x ,y;
            scanf("%d %d %d", &x, &y, &t);
            star.push(make_pair(t, make_pair(x, y)));
            x>=0&&y>=0? bad[x][y] = 1:0;
            x+1>=0&&y>=0? bad[x+1][y] = 1:0;
            x-1>=0&&y>=0? bad[x-1][y] = 1:0;
            x>=0&&y+1>=0? bad[x][y+1] = 1:0;
            x>=0&&y-1>=0? bad[x][y-1] = 1:0;
            
        }
        queue<pair<pair<int, int>, int>> que;
        que.push(make_pair(make_pair(0,0),0));
        while(!que.empty()){
            auto pos = que.front().first;
            auto time = que.front().second;
            que.pop();
        
            if(!bad[pos.first][pos.second]){
                cout << time;
                return 0;
            }

            while(!star.empty()&&star.top().first == time){
                auto sp = star.top().second;
                star.pop();
                sp.first>=0&&sp.second>=0? vit[sp.first][sp.second] = 1:0;
                sp.first+1>=0&&sp.second>=0? vit[sp.first+1][sp.second] = 1:0;
                sp.first-1>=0&&sp.second>=0? vit[sp.first-1][sp.second] = 1:0;
                sp.first>=0&&sp.second+1>=0? vit[sp.first][sp.second+1] = 1:0;
                sp.first>=0&&sp.second-1>=0? vit[sp.first][sp.second-1] = 1:0;
            }

            if(vit[pos.first][pos.second]){continue;}

            vit[pos.first][pos.second] = 1;

            pos.first+1>=0&&pos.second>=0? que.push(make_pair(make_pair(pos.first+1,pos.second),time+1)),0:0;        
            pos.first-1>=0&&pos.second>=0? que.push(make_pair(make_pair(pos.first-1,pos.second),time+1)),0:0;        
            pos.first>=0&&pos.second+1>=0? que.push(make_pair(make_pair(pos.first,pos.second+1),time+1)),0:0;        
            pos.first>=0&&pos.second-1>=0? que.push(make_pair(make_pair(pos.first,pos.second-1),time+1)),0:0;        

        }
        cout << -1;
        return 0;

    }
