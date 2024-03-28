#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(1e5+30))

int school[MAX_SIZE];
int student[MAX_SIZE];

int n, m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        scanf("%d", school+i);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", student+i);
    }
    sort(school, school + n);
    long long sum = 0;
    for(int i = 0; i < m; ++i){
        int _idx = lower_bound(school, school+n, student[i])-school;
        if(_idx == 0){
            sum += abs(school[_idx]-student[i]);
        }else if(_idx == n){
            sum += abs(school[_idx-1]-student[i]);
        }else{
            sum += min(abs(school[_idx-1]-student[i]),abs(school[_idx]-student[i]));
        }
    }
    cout << sum;
    return 0;
}