#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Flower{
    string name;
    int point;
    int id;
};


int main(){
    int n; cin >> n;
    map<string, pair<int, int>> mp;
    for(int i = 0; i < n; ++i){
        string name;
        int p;
        cin >> name >> p;
        if(mp.count(name)){
            mp[name].first += p;
            mp[name].second = i;
        }else{
            mp[name] = {p, i};
        }
    }
    vector<Flower> flowers;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        flowers.push_back({itr->first, itr->second.first, itr->second.second});

    }
    sort(flowers.begin(), flowers.end(), [](const Flower& lhs, const Flower& rhs)->bool {
        if(lhs.point != rhs.point) return lhs.point < rhs.point;
        return lhs.id < rhs.id;
    });
    cout << flowers.begin()->name << '\n';
    cout << flowers.begin()->point + 1000;
    return 0;
}