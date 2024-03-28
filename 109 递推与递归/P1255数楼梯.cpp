#include <stdio.h>
#define MAX_SIZE 10000
int n_0[MAX_SIZE]{2};
int n_1[MAX_SIZE]{1};
int n_2[MAX_SIZE]{1};

int main(){
    int n; scanf("%d", &n);
    if(n==1){
        printf("1");
        return 0;
    }else if(n == 2 ){
        printf("2");
        return 0;
    }
//TODO 高精度
    for(int i = 3; i <= n; ++i){
        //n_2 = n_1, n_1 = n_0;
        //n_0 = n_1 + n_2
        for(int i = 0; i < MAX_SIZE; ++i){
            n_2[i] = n_1[i], n_1[i] = n_0[i];
        }
        for(int i = 0; i < MAX_SIZE; ++i){
            n_0[i] = n_1[i] + n_2[i];
        }
        for(int i = 0; i < MAX_SIZE -1; ++i){//进位
            n_0[i+1] += n_0[i]/10;
            n_0[i]%=10; 
        }
    }

    bool print = false;
    for(int i = MAX_SIZE-1; i >=0; --i){
        if(print == false){
            if(n_0[i]!=0){
                print = true;
            }
        }
        if(print == true){
            printf("%d", n_0[i]);
        }
    }
    return 0;
}