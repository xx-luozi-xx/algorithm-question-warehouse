#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(1e6+30))

int data[MAX_SIZE];
int n, m; 

bool check(int h){
    long long have = 0;
    for(int i = 0; i < n; ++i){
        have += h<data[i]? data[i]-h:0;
    }
    return have >= m;
}
int main(){
    cin >>n >>m;
    int _max = 0, _min = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
        _max = max(data[i], _max);
    }
    while(1){
        int mid = (_min+_max)/2;
        if(check(mid)&&!check(mid+1)){
            printf("%d", mid);
            return 0;
        }else if(!check(mid)){//太高了需要降
            _max = mid-1;
        }else{//太矮了需要升
            _min = mid+1;
        }
    }
}