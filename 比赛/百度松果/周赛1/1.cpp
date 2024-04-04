//https://www.matiji.net/exam/brushquestion/26/3181/1DC60EA6DF83A333301CFFE1407FBA59
#include <list>
#include <iostream>
#include <assert.h>
using namespace std;
const int MAX_SIZE = 100;
int n, m;
int num[MAX_SIZE][MAX_SIZE];

void op(list<list<int>>& lst){
    lst.push_front(lst.back());
    lst.pop_back();

    lst.front().push_front(lst.front().back());
    lst.front().pop_back();
}

int main(){
    cin >> n >> m;
    assert(n <= 50 and m <= 50);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> num[i][j];
        }
    }
    list<list<int>> L;
    for(int j = 0; j < m; ++j){
        list<int> l;
        for(int i = 0; i < n; ++i){
            l.push_back(num[i][j]);
        }
        L.push_back(l);
    }
    int k; cin >> k;
    while(k--){
        op(L);
    }
    //printf
    {
    int j = 0;
    for(auto itr = L.begin(); itr != L.end(); ++itr, ++j){
        int i = 0;
        for(auto jtr = itr->begin(); jtr != itr->end(); ++jtr, ++i){
            num[i][j] = *jtr;
        }
    }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << num[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
