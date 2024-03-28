#include <stdio.h>
#define MAX_SZIE (1000+5)

int dp1[MAX_SZIE]{1};
int dp2[MAX_SZIE]{1};
int dp3[MAX_SZIE]{1};

void add(int* result,const int* lhs,const int* rhs);
void assign(int* lhs, const int* rhs);
void print(const int* big_num);

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    n-=m;
    for(int i = 2; i <= n; ++i){
        // dp3 = dp1 + dp2;
        // dp1 = dp2;
        // dp2 = dp3;
        add(dp3, dp1, dp2);
        assign(dp1, dp2);
        assign(dp2, dp3);
    }
    print(dp3);
    return 0;
}
void add(int* result,const int* lhs,const int* rhs){
    for(int i = 0; i < MAX_SZIE-1; ++i){
        result[i] = lhs[i] + rhs[i];
    }
    for(int i = 0; i < MAX_SZIE-1; ++i){
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
}
void assign(int* lhs, const int* rhs){
    for(int i = 0; i < MAX_SZIE; ++i){
        lhs[i] = rhs[i];
    }
}
void print(const int* big_num){
    bool start_bit = false;
    for(int i = MAX_SZIE-1; i >= 0; --i){
        if(start_bit == true){
            putchar(big_num[i]+'0');
        }else{
            if(big_num[i] != 0){
                start_bit = true;
                putchar(big_num[i]+'0');
            }
        }
    }
}
