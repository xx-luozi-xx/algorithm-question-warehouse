#include <iostream>
#include <list>
using namespace std;

int main(){
    long long n; cin >> n;
    n--;
    list<int> lst;
    if(n == 0){
        cout << "0";
        return 0;
    }
    while(n){
        lst.push_back((n%5)*2);
        n/=5;
    }
    for(auto itr = lst.rbegin(); itr != lst.rend(); ++itr){
        cout << *itr;
    }
    return 0;
}