#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int max_ = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        max_ = max(a+b, max_);
    }
    cout << max_;
    return EXIT_SUCCESS;
}