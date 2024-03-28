#include <bits/stdc++.h>
using namespace std;
int n, m;
list<int> lst;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        lst.push_back(i);
    }

    auto itr = lst.begin();
    int num = 1;
    while(!lst.empty()){
        if(num%m == 0){
            cout << *itr << ' ';
            itr = lst.erase(itr);
            if(itr == lst.end()){
                itr = lst.begin();
            }
        }else{
            ++itr;
            if(itr == lst.end()){
                itr = lst.begin();
            }
        }
        ++num;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for(int i = 1; i <= n; ++i){
        que.push(i);
    }
    int num = 0;
    while(!que.empty()){
        ++num; num%=m;
        int now = que.front(); que.pop();
        if(num == 0){
            cout << now << ' ';
        }else{
            que.push(now);
        }
    }
}