#include <iostream>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    if(1<<(n-1)>=m){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}