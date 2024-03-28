#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1e5;

int isnprime[MAX_SIZE]{1,1,0};
int prime[MAX_SIZE];
int prime_len = 0;

void prime_init(){
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            prime[prime_len++] = i;
        }
        for(int j = 0; j < prime_len and i*prime[j]<MAX_SIZE; ++j){
            isnprime[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}

void dooo(int a0, int a1, int b0, int b1){
    if(b1%a1 != 0){
        printf("0\n");
        return;
    }

    int base = b1/a1;
    int b1_b0 = b1/b0;
    int a0_a1 = a0/a1;
    int b_use = 1;
    //printf("\nbase = %d, b1/b0 = %d, a0/a1 = %d\n", base, b1_b0, a0_a1);
    int prime_i = 0;
    while(b1_b0 > 1 and prime_i < prime_len){
        if(b1_b0 % prime[prime_i] == 0){
            while(base % prime[prime_i] == 0){
                base /= prime[prime_i];
                b_use *= prime[prime_i];
            }
            b1_b0 /= prime[prime_i];
        }else{
            prime_i++;
        }
    }

    if(b1_b0 != 1){
        if(base % b1_b0 == 0){
            base /= b1_b0;
            b_use *= b1_b0;
        }
    }

    if(__gcd(a0/a1, b_use) != 1){
        printf("0\n");
        return;
    }

    prime_i = 0;
    while(a0_a1 > 1 and prime_i < prime_len){
        if(a0_a1 % prime[prime_i] == 0){
            while(base % prime[prime_i] == 0){
                base /= prime[prime_i];
            }
            a0_a1 /= prime[prime_i];
        }else{
            prime_i++;
        }
    }
    if(a0_a1 != 1){
        if(base % a0_a1 == 0){
            base /= a0_a1;
        }
    }

    prime_i = 0;
    unsigned long long ans = 1;
    int cnt = 0;
    while(base > 1 and prime_i < prime_len){
        if(base % prime[prime_i] == 0){
            cnt++;
            base /= prime[prime_i];
        }else{
            ans *= cnt+1;
            cnt = 0;
            prime_i ++;
        }
    }
    ans *= cnt+1;
    cnt = 0;
    if(base != 1){
        ans *= 2;
    }
    printf("%llu\n", ans);
}

int main(){
    prime_init();
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        dooo(a0, a1, b0 , b1);
    }
    return 0;
}