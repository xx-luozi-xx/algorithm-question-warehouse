#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        a>>=1;
        sum += min(a, b);
    }
    cout << sum;
    return EXIT_SUCCESS;
}