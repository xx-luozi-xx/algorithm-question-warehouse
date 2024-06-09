//单调栈
// https://www.matiji.net/exam/dohomework/6418/1
#include <iostream>
#include <stack>
#include <set>
using namespace std;
const int MAX_SIZE = 1e6+30;

int n;
int h[MAX_SIZE];
int l[MAX_SIZE];
int r[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> h[0] >> h[i];
    }
    stack<pair<int, int>> stk; // <num, idx>
    stk.push({-100, 0});
    for(int i = 1; i <= n; ++i){
        while(stk.top().first >= h[i]){
            stk.pop();
        }
        l[i] = stk.top().second;
        stk.push({h[i], i});
    }

    stk = stack<pair<int, int>>() ; // <num, idx>
    stk.push({-100, n+1});
    for(int i = n; i >= 1; --i){
        while(stk.top().first >= h[i]){
            stk.pop();
        }
        r[i] = stk.top().second;
        stk.push({h[i], i});
    }

    set<pair<int, int>> ranges;
    for(int i = 1; i <= n; ++i){
        ranges.insert({l[i], r[i]});
    }
    cout << ranges.size();
    return 0;
}