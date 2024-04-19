//链表 https://www.matiji.net/exam/brushquestion/23/3846/4C6668FEB8CFD6520DE73B365B31D1A4
#include <list>
#include <string>
#include <iostream>
using namespace std;
const int MAX_SIZE = 1e4+30;
const int MAX_STR_SIZE = 1e5+30;
const int INF = 0x3f3f3f3f;
int n;
string strs[MAX_SIZE];
string str;

int next_[MAX_STR_SIZE][30];
inline int& next(int pos, char c){
    return next_[pos][c-'a'];
}

list<int> pos[128];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> strs[i];
    }
    cin >> str;
    str = ("a"+str);
    for(int i = 0; i < str.size(); ++i){
        pos[str[i]].push_back(i);
    }
    for(char i = 'a'; i <= 'z'; ++i){
        pos[i].push_back(INF);
    }
    for(int i = 0; i < str.size(); ++i){
        for(char j = 'a'; j <= 'z'; ++j){
            while(pos[j].front() <= i){
                pos[j].pop_front();
            }
            next(i, j) = pos[j].front();
        }
    }

    for(int i = 0; i < n; ++i){
        int now = 0;
        for(auto c : strs[i]){
            now = next(now, c);
            if(now == INF){
                cout << "NO\n";
                goto next_loop;
            }
        }
        cout << "YES\n";
        next_loop:void();
    }
    return 0;
}