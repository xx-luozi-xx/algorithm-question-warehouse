#include <bits/stdc++.h>
using namespace std;
const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);
const int MAX_N = 1e5+30;

int n, p;
int info[MAX_N];


int main(){
    cin >> n >> p;
    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        info[num]++;
        int cnt = max(1, i*p/100);
        int j = 650;
        int sum = 0;
        while(sum < cnt){
            sum += info[j--];
        }
        cout << j+1 << ' ';
    }
    return 0;    
}