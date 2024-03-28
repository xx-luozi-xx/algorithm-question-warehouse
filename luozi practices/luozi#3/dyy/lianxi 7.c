#include<stdio.h>
#include<math.h>
int main(){
    int n,m;
    int c[10000]={0},a[10000]={0},b[10000]={0};
    a[0]=1;
    b[0]=2;
    scanf("%d",&n);
    if(n==1)printf("1");
    else if(n==2)printf("2");
    else{
        for(int i=3;i<=n;i++){
            for(int j=0;j<10000;j++){
                c[j]=a[j]+b[j];
            }
            for(int i=0;i<10000;i++){
                while(c[i]>=10){
                    c[i]=c[i]-10;
                    c[i+1]=c[i+1]+1;
                }
            }   
            for(int j=0;j<10000;j++){
                a[j]=b[j];
            }
            for(int j=0;j<10000;j++){
                b[j]=c[j];
            }
        }
        for(int i=9999;i>=0;i--){
            if(c[i]!=0){
                m=i;
                break;
            }
        }
        for(int i=m;i>=0;i--){
            printf("%d",c[i]);
        }
    }
    return 0;
}


#include <stdio.h>
#define MAX_SZIE (1000+5)

#define true 1
#define false 0
typedef int bool;

int dp1[MAX_SZIE]={1};
int dp2[MAX_SZIE]={2};
int dp3[MAX_SZIE]={1};

void add(int* result,const int* lhs,const int* rhs);
void assign(int* lhs, const int* rhs);
void print(const int* big_num);

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    n-=m;
    for(int i = 2; i <= n; ++i){
        //* dp3 = dp1 + dp2;
        //* dp1 = dp2;
        //* dp2 = dp3;
        add(dp3, dp1, dp2);
        assign(dp1, dp2);
        assign(dp2, dp3);
    }
    print(dp3);
    return 0;
}
void add(int* result, const int* lhs, const int* rhs){
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
