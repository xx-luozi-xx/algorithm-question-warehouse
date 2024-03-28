#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        sum += max(a, b);
    }
    cout << sum;
    return EXIT_SUCCESS;
}