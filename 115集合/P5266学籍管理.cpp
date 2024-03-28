#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);

int main(){
    int n; cin >> n;
    unordered_map<string, int> mp;
    while(n--){
        int op; cin >> op;
        if(op == 1){
            string name;
            int score;
            cin >> name >> score;
            if(mp.count(name)){
                mp[name] = score;
            }else{
                mp.insert({name, score});
            }
            cout << "OK\n";
        }else if(op == 2){
            string name;
            cin >> name;
            if(mp.count(name)){
                cout << mp[name] << '\n';
            }else{
                cout << "Not found\n";
            }
        }else if(op == 3){
                        string name;
            cin >> name;
            if(mp.count(name)){
                mp.erase(name);
                cout << "Deleted successfully\n";
            }else{
                cout << "Not found\n";
            }
        }else if(op == 4){
            cout << mp.size() << '\n';
        }else{
            void();
        }
    }
    return 0;
}