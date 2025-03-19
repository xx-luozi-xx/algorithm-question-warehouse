// https://www.luogu.com.cn/problem/P2216
#include <iostream>
#include <list>
using namespace std;
const int MAX_SIZE = 1e3+30;

int a, b, n;
int num[MAX_SIZE][MAX_SIZE];

int max_v[MAX_SIZE][MAX_SIZE];//[1, a] x [n, b]
int min_v[MAX_SIZE][MAX_SIZE];

int max_ans[MAX_SIZE][MAX_SIZE];//[n, a] x [n, b]
int min_ans[MAX_SIZE][MAX_SIZE];


int main(){
    cin >> a >> b >> n;
    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= b; ++j){
            cin >> num[i][j];
        }
    }
    //making max val
    //row
    for(int i = 1; i <= a; ++i){
        list<pair<int, int>> que_max; // <val, pos>
        for(int j = 1; j <= b; ++j){
            while(!que_max.empty() and que_max.front().second <= j-n){
                que_max.pop_front();
            }
            
            int val = num[i][j];
            while(!que_max.empty() and que_max.back().first <= val){
                que_max.pop_back();
            }
            que_max.push_back({val, j});

            if(j < n){
                continue;
            }else{
                max_v[i][j] = que_max.front().first;
            }
        }
    }
    //col
    for(int j = n; j <= b; ++j){
        list<pair<int, int>> que_max; // <val, pos>
        for(int i = 1; i <= a; ++i){
            while(!que_max.empty() and que_max.front().second <= i-n){
                que_max.pop_front();
            }
            
            int val = max_v[i][j];
            while(!que_max.empty() and que_max.back().first <= val){
                que_max.pop_back();
            }
            que_max.push_back({val, i});

            if(i < n){
                continue;
            }else{
                max_ans[i][j] = que_max.front().first;
            }            
        }
    }

    //making min val
    //row
    for(int i = 1; i <= a; ++i){
        list<pair<int, int>> que_min; // <val, pos>
        for(int j = 1; j <= b; ++j){
            while(!que_min.empty() and que_min.front().second <= j-n){
                que_min.pop_front();
            }
            
            int val = num[i][j];
            while(!que_min.empty() and que_min.back().first >= val){
                que_min.pop_back();
            }
            que_min.push_back({val, j});

            if(j < n){
                continue;
            }else{
                min_v[i][j] = que_min.front().first;
            }
        }
    }
    //col
    for(int j = n; j <= b; ++j){
        list<pair<int, int>> que_min; // <val, pos>
        for(int i = 1; i <= a; ++i){
            while(!que_min.empty() and que_min.front().second <= i-n){
                que_min.pop_front();
            }
            
            int val = min_v[i][j];
            while(!que_min.empty() and que_min.back().first >= val){
                que_min.pop_back();
            }
            que_min.push_back({val, i});

            if(i < n){
                continue;
            }else{
                min_ans[i][j] = que_min.front().first;
            }            
        }
    }

    int ans = 0x3f3f3f3f;

    for(int i = n; i <= a; ++i){
        for(int j = n; j <= b; ++j){
            ans = min(ans, max_ans[i][j] - min_ans[i][j]);
        }
    }
    cout << ans;
    return 0;
}