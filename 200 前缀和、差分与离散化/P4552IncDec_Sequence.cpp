#include <iostream>
using namespace std;

int main(){
    int n;
    int first;
    int last;
    cin >> n;
    long long ans = 0;
    int pre = 0;
    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        if(i == 0){
            first = num;
        }else if(i == n-1){
            last = num;
        }

        if(i != 0){
            ans += abs(num-pre);
        }
        pre = num;
    }
    ans += abs(last-first);
    cout << ans/2 <<'\n'<< abs(last-first)+1;
    return 0;
}