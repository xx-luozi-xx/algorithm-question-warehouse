#include <stdio.h>
#include <cmath>
int prime[10000];
bool ifPrime(int a){\
    if(a<2){
        return 0;
    }
    for(int i = 2;i<=sqrt(a);i++){
        if(!(a%i)){
            return 0;
        }
    }
    return 1;
}
void spawnPrime(){    
    for(int i = 2, ans = 0;i<=10000;i++){
        ifPrime(i)?prime[ans++] = i:0;
    }
}
int main(){
    spawnPrime();
    int n;scanf("%d",&n);
    for(int a = 4;a<= n;a+=2){
        for(int i = 0;i<10000;i++){
            for(int j = i;j<10000;j++){
                if(prime[i]+prime[j]==a){
                    printf("%d=%d+%d\n",a,prime[i],prime[j]);
                    goto next_a;
                }
            }
        }
        next_a:;
    }
    return 0;
}