#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(2*1e5+30))

long long data[MAX_SIZE];

int main(){
    int n, c; cin >> n >> c;
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    sort(data, data+n);
    long long cnt = 0;
    for(int i = 0; i < n; ++i){
        int lo = lower_bound(data, data+n, c+data[i])-data;
        int up = upper_bound(data, data+n, c+data[i])-data;
        cnt += up-lo;
    }
    printf("%lld", cnt);
    return 0;
}