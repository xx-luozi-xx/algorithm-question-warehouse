#include <bits/stdc++.h>
using namespace std;
int data[1000000+30];
int main(){
    int n, m;
    cin >> n >>m;
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    for(int j = 0; j < m; ++j){
        int input; scanf("%d", &input);
        int idx = lower_bound(data, data+n, input) - data;
        data[idx] == input ? printf("%d ", idx+1):printf("-1 ");
    }
    return 0;
}