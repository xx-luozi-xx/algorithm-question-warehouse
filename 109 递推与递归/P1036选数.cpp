#include <stdio.h>
#include <string.h>

#define PRIME3

#define MAX_PRIME (10000000+5)
int N, K;

int data[30];
bool choosed[30]{};

int choose_set[30]{};
int set_size = 0;

int num_of_prime = 0;

bool isnprime[MAX_PRIME]{1,1,0};

#ifdef PRIME3
int prime[MAX_PRIME]{};
int prime_cnt = 0;
#endif

void init_prime(){
#ifdef PRIME1
    for(int i = 2; i < MAX_PRIME; ++i){//*朴素筛(O(nlogn)) 用每个数的所有倍数删掉合数
        for(int j = 2; i*j < MAX_PRIME; ++j){
                isnprime[i*j] = true;
        }
    }
#endif
#ifdef PRIME2
    for(int i = 2; i < MAX_PRIME; ++i){//*埃筛(O(nloglogn)) 用每个质数的倍数删掉合数
        if(!isnprime[i]){
            for(int j = 2; i*j < MAX_PRIME; ++j){
                isnprime[i*j] = true;
            }
        }
    }
    #endif
#ifdef PRIME3
    for(int i = 2; i < MAX_PRIME; ++i){//*欧拉筛(O(n)) 每个合数只被 最小质因数*最大的因数 筛掉， 所以对于每个数，只筛一次
        if(isnprime[i] == 0){//*存入获取的质数
            prime[prime_cnt++] = i;
        }
        for(int j = 0; j < prime_cnt && i*prime[j] < MAX_PRIME; ++j){
            isnprime[prime[j] * i] = 1; //*最小质因数*最大的因数
            if(i%prime[j] == 0){//* 最坏也是i为质数，在筛掉i*i后退出
                break;//* 这里及时退出确保了 每个合数只被最小的质因数筛掉(留给之后筛)
            }
        }
    }
#endif
    // for(int i = 0; i < 100; ++i){
    //     if(!isnprime[i]){
    //         printf("%d\n", i);
    //     }
    // }
}

void choose_number(int n, int begin){
    if(n == 0){
        //todo 取得一种情况
        int sum = 0;
        for(int i = 0; i < set_size; ++i){
            sum+=choose_set[i];
        }
        num_of_prime += !isnprime[sum];
    }

    for(int i = begin; i < N; ++i){
        if(choosed[i] == 0){
            choosed[i] = 1;
            choose_set[set_size++] = data[i];
            choose_number(n-1, i);
            set_size--;
            choosed[i] = 0;
        }
    }
}

int main(){

    init_prime();

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", data+i);
    }

    choose_number(K, 0);
    printf("%d", num_of_prime);
    return 0;
}