#include <stdio.h>
#include <math.h>
#define MAX_SIZE (100000000+10)

bool isnprime[MAX_SIZE];

int prime[6000000];
int prime_size = 0;

void get_prime(int N) {
    isnprime[0]=isnprime[1]=1;
    isnprime[2]=0;
    
    for (int i = 2; i <= N; ++i) {
        if (!isnprime[i]) {
            prime[prime_size++] = i;
        }
        
        for (int j = 0; prime[j]*i < N && j < prime_size; ++j) {
            isnprime[prime[j]*i] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    get_prime(n);
    while (q--) {
        int rank;
        scanf("%d", &rank);
        printf("%d\n", prime[rank - 1]);
    }
    return 0;
}

