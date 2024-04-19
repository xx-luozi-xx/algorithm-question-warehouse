//全错排 https://www.matiji.net/exam/brushquestion/46/3181/1DC60EA6DF83A333301CFFE1407FBA59

#include <iostream>
#define int long long
using namespace std;
int arr[30]={0,0,1};
signed main(){
    for(int i = 3; i <= 29; ++i){
        arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
    }
    int n; cin >> n;
    cout << arr[n];
    return 0;
}

