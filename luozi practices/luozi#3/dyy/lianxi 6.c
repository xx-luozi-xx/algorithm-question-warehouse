#include<stdio.h>
#include<math.h>
int main(){
    int n,a=2,b=1;
    int panduan=1;
    scanf("%d",&n);
    if(n==1) printf("0");
    else {
        printf("2\n");
        for(int i=3;;i++){
            panduan=1;
            const int MAX_J = sqrt(i);
            for(int j=2;/*j<=sqrt(i)*/ j <= MAX_J;j++){
                if(i%j==0)panduan=0;
            }
            if(a+i>n)break;
            if(panduan==1){
                a=a+i;
                printf("%d\n",i);
                b=b+1;
            }
        }
        printf("%d",b);
    }
    return 0;
}

#define MAX_N 1000

int isnprime[MAX_N] = {1,1,0};//* 0  1

void getPrime(){//*朴素筛 O(n*logn)
    for(int i = 2; i < MAX_N; ++i){  //*筛掉每个数的倍数  
        for(int j = i; i*j<MAX_N; ++j){
            isnprime[i*j] = 1;
        }//*  6 = 2*3 = 3*2
         //* 9 = 3*3
    }
}

void getPrime2(){//*埃筛 O(n*loglogn)
    for(int i = 2; i < MAX_N; ++i){//*筛掉每个质数的倍数  
        if(isnprime[i] == 0){
            for(int j = i; i*j<MAX_N; ++j){
                isnprime[i*j] = 1;
            }//*16 = 4*4 = 2*8 = 2*2*2*2
            //*  12 = 2*2*3   (2*6)

        }
    }
}

int prime[MAX_N] = {};
int prime_size = 0;

void getPirme3(){//*欧拉筛  O(n)
    for(int i = 2; i < MAX_N; ++i){
        if(isnprime[i] == 0){
            prime[prime_size++] = i;
        }

        for(int j = 0; j < prime_size; ++j){
            //*  42 = 2*3*7    2*21  3*14  7*6
            //*                      2*14  
            isnprime[prime[j]*i] = 1;//! 每个合数只被筛掉一遍
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}



