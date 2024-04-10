// map模板题
// https://www.matiji.net/exam/brushquestion/39/3181/1DC60EA6DF83A333301CFFE1407FBA59
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N,M,T;
int main(){
    cin >> N >> M >> T;
    vector<string> items;
    for(int i = 0; i < N; ++i){
        string input; cin >> input;
        items.push_back(input);
    }
    for(int i = 0; i < T; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        items[a].swap(items[b]);
    }
    map<string, int> mp;
    for(int i = 0; i < N; ++i){
        mp[items[i]] = i+1;
    }
    for(int i = 0; i < M; ++i){
        string str; cin >> str;
        cout << mp[str] << '\n';
    }
    return 0;
}