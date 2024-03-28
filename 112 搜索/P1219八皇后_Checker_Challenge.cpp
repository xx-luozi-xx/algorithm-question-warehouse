#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 30

int row[MAX_SIZE];
int col[MAX_SIZE];
int xxx[MAX_SIZE];
int yyy[MAX_SIZE];

int n;

int bag[MAX_SIZE];
int bag_size;

long long cnt;
int print = 0;

void dfs(int times){
    if(times == 0){
        if(print<3){
            for(int i = 0; i < n; ++i){
                printf("%d ", bag[i]+1);
            }
            printf("\n");
            print++;
        }
        cnt++;
        return;
    }
    const int j = n - times;
    for(int i = 0; i < n; ++i){
        if(!row[i]&&!col[j]&&!xxx[i+j]&&!yyy[i-j+n]){
            row[i] = 1;
            col[j] = 1;
            xxx[i+j] = 1;
            yyy[i-j+n] = 1;

            bag[bag_size++] = i;

            dfs(times-1);

            bag_size--;

            row[i] = 0;
            col[j] = 0;
            xxx[i+j] = 0;
            yyy[i-j+n] = 0;
        }
    }



}

int main(){
    cin >> n;
    dfs(n);
    cout << cnt;
    return 0;
}