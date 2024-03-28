#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 30

int N, K;
int data[MAX_SIZE];

int choose[MAX_SIZE];
int choose_size;

long long cnt;

bool ispri(int num){
    if(num < 2){return 0;}
    for(int i = 2; i*i<=num; ++i){
        if(num%i==0){return 0;}
    }
    return 1;
}

void dfs(int times, int begin){
    if(times == 0){
        long long sum = 0;
        for(int i = 0; i < choose_size; ++i){
            //printf("%d ", choose[i]);
            sum += choose[i];
        }
        //printf("\n");
        cnt += ispri(sum);
        return;
    }

    for(int i = begin; i < N; ++i){
        choose[choose_size++] = data[i];
        dfs(times-1, i+1);
        choose_size--;
    }
}



int main(){
    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        scanf("%d", data+i);
    }
    dfs(K,0);
    cout << cnt;
    return 0;
}