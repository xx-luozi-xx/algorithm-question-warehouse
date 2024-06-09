/**
差分，前缀和，区间修改
https://www.matiji.net/exam/dohomework/6418/6
毒瘤数据 a== b
*/
#include <iostream>
using namespace std;
const int MAX_SIZE = 1e5;

int n, h, f;
int arr[MAX_SIZE];

int main(){
    cin >> n >> h >> f;
    arr[1] = h;
    for(int i = 1; i <= f; ++i){
        int a, b; cin >> a >> b;
        if(a == b) continue;
        if(a >= b) swap(a, b);
        a++;
        arr[a]--;
        arr[b]++;
    }
    for(int i = 1; i <= n; ++i){
        arr[i] += arr[i-1];
        cout << arr[i] << '\n';
    }
    return 0;
}