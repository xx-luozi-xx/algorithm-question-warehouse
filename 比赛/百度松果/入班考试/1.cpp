#include <iostream>
using namespace std;

int main(){
    int n, N;
    scanf("%d,%d", &n, &N);
    long long ans = 0;
    for(int i = n; i <= N; ++i){
        if(i%2 == 0 and i%3 == 0){
            ans += i;
        }
    }
    cout << ans;
    return 0;
}