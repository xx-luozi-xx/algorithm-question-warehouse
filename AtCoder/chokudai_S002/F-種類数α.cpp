#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<pair<int, int>> st;
    long long sum = 0;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a < b){
            swap(a, b);
        }
        if(st.count({a,b})){

        }else{
            st.insert({a,b});
            sum++;
        }
    }
    cout << sum;
    return EXIT_SUCCESS;
}