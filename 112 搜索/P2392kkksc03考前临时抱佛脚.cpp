#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
#define JJ 5

int a[MAX_SIZE], a_size, A;
int b[MAX_SIZE], b_size, B;
int c[MAX_SIZE], c_size, C;
int d[MAX_SIZE], d_size, D;

int dp[MAX_SIZE][MAX_SIZE*MAX_SIZE];

int bag(const int stuff[], int size, int bag){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j <= bag; ++j){
            if(stuff[i]>j){
                dp[i+JJ][j] = dp[i-1+JJ][j];
            }else{
                dp[i+JJ][j] = max(dp[i-1+JJ][j], dp[i-1+JJ][j-stuff[i]]+stuff[i]);
            }
        }
    }
    return dp[size-1+JJ][bag];
}

int main(){
    cin >> a_size >> b_size >> c_size >> d_size;
        for(int i = 0; i < a_size; ++i){
            scanf("%d", a+i);
            A+=a[i];
        }
        for(int i = 0; i < b_size; ++i){
            scanf("%d", b+i);
            B+=b[i];
        }
        for(int i = 0; i < c_size; ++i){
            scanf("%d", c+i);
            C+=c[i];
        }
        for(int i = 0; i < d_size; ++i){
            scanf("%d", d+i);
            D+=d[i];
        }
    long long sum = 0;
    sum += A-bag(a, a_size, A/2);
    sum += B-bag(b, b_size, B/2);
    sum += C-bag(c, c_size, C/2);
    sum += D-bag(d, d_size, D/2);

    cout << sum;
    return 0;
}

