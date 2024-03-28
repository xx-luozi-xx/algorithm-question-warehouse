#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define v2 vector<vector<int>>
int H, W; 

string coder(const v2& arr){
    string ret;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            int x = arr[i][j];
            ret += char(x%10+'0');
            ret += char(x/10+'0');
        }
    }    
    return ret;
}

int main(){
    cin >> H >> W;
    vector<vector<int>> init(H+1, vector<int>(W+1, 0));
    vector<vector<int>> tar = init;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cin >> init[i][j];
        }
    }
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            tar[i][j] = (i-1)*W+j;
        }
    }
    unordered_map<string, int> mp;
    queue<pair<v2, int>> que;//matrix, step
    que.push({init, 0});
    while(!que.empty()){
        v2 now = que.front().first;
        int step = que.front().second;
        que.pop();
        if(step > 20){
            continue;
        }
        if(mp[coder(now)]++ != 0){
            continue;
        }
        if(now == tar){
            cout << step;
            return 0;
        }
        for(int x = 0; x <= 1; ++x){
            for(int y = 0; y <= 1; ++y){
                v2 next = now;
                for(int i = 1; i <= H-1; ++i){
                    for(int j = 1; j <= W-1; ++j){
                        next[i+x][j+y] = now[H-i+x][W-j+y];
                    }
                }
                que.push({next, step+1});
            }
        }        
    }
    cout << -1;
    return 0;
}