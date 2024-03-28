#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 20

int n;
int s[MAX_SIZE];
int b[MAX_SIZE];

long long min_ = __INT_MAX__;

int choose[MAX_SIZE];
int choose_size;

void dfs(int times, int begin){
    if(times == 0){
        long long S = 1;
        long long B = 0;
        for(int i = 0; i < choose_size; ++i){
            S*=s[choose[i]];
            B+=b[choose[i]];
        }
        min_ = min(abs(S-B), min_);
        return;
    }

    for(int i = begin; i < n; ++i){
        choose[choose_size++] = i;
        dfs(times-1, i+1);
        choose_size--;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", s+i, b+i);
    }
    for(int i = 1; i <= n; ++i){
        dfs(i, 0);
    }
    cout << min_;
    return 0;
}