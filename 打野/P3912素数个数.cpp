#include <iostream>
#include <bitset>
using namespace std;
const int MAX_SIZE = 1e8+30;
char isnprime[MAX_SIZE];
int main(){
    isnprime[0] = 1;
    isnprime[1] = 1;
    for(int i = 2; i*i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            for(int j = i+i; j < MAX_SIZE; j+=i){
                isnprime[j] = 1;
            }
        }
    }
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!isnprime[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}

