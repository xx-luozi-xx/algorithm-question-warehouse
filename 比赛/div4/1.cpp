#include <iostream>
using namespace std;

int main(){
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    int g = 0;
    while(q*k>p*(n+g)){
        g++;
    }
    cout << g;

}