#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;
int n;
int num[MAX_SIZE];


int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    int l = 1; int r = 1;
    long long sum = num[1];
    long long ans = 0;
    while(r <= n){
        if(sum == n){
            ans ++;
            sum += num[++r];
        }else if(sum < n){
            sum += num[++r];
        }else if(sum > n){
            sum -= num[l++];
        }
    }
    cout << ans;
    return 0;
}