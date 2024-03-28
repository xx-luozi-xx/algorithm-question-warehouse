#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_SIZE = 1e5+30;
int n;
int num[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    int times = 0;
    for(int i = 1; i <= n; ++i){
        while(num[i] != i){
            swap(num[i], num[num[i]]);
            times ++;
        }
    }
    if(times < n and (n-times)%2 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}