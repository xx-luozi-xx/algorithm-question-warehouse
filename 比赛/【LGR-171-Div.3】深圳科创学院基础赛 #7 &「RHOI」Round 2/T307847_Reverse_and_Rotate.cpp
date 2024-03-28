#include <iostream>
#include <string>
#include <list>
#define int long long
using namespace std;

signed main(){
    string str; cin >> str;
    int n; cin >> n;
    int sft = 0;
    int rot = 1;
    while(n-->0){
        string op; cin >> op;
        if(op == "<"){
            int x; cin >> x;
            x *= rot;
            sft -= x;
        }else if(op == ">"){
            int x; cin >> x;
            x *= rot;
            sft += x;
        }else{
            rot *= -1;
        }
        //printf("{%d, %d}\n", sft, rot);
    }
    list<char> lst;
    for(int i = 0; i < str.size(); ++i){
        lst.push_back(str[i]);
    }
    int str_size = str.size();
    sft=(sft%str_size+str_size)%str_size;
    //printf("[%d][%d]\n",sft, str_size);
    for(int i = 0; i < sft; ++i){
        lst.push_front(lst.back());
        lst.pop_back();
    }
    if(rot == 1){
        for(auto itr = lst.begin(); itr != lst.end(); ++itr){
            cout << *itr;
        }
    }else{
        for(auto itr = lst.rbegin(); itr != lst.rend(); ++itr){
            cout << *itr;
        }
    }
    return 0;
}  