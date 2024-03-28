#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int (1e5+30))

int data[MAX_SIZE];
int n, k;

bool check(int l){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += data[i]/l;
    }
    return sum >= k;
}

int main(){
    cin >>n >>k;
    int _min = 1, _max = 1;
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
        _max = max(data[i], _max);
    }
    while(1){
        int mid = (_min + _max)/2;
        if(_max < _min){
            printf("0");
            return 0;
        }
        if(check(mid)&&!check(mid+1)){
            cout << mid;
            return 0;
        }else if(!check(mid)){
            _max = mid-1;
        }else{
            _min = mid+1;
        }
    }
}