#include <iostream>
using namespace std;
const int MAX_SIZE = 1e6+30;

int n;
int num[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    int now = 1;
    int step = 0;
    while(now < n){
        now += num[now];
        step ++;
    }
    cout << (now == n? "Yes":"No") << '\n';
    cout << step;
    return 0;
}