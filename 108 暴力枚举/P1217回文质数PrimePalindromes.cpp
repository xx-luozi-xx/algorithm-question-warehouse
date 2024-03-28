#include <stdio.h>
#include <math.h>

int a, b;

int data[20] = {0,1,2,3,4,5,6,7,8,9};

int out[20]{};
int out_size = 0;

bool EOP = false;

bool is_prime(int num){
    if(num < 2){
        return false;
    }
    if(num == 2){
        return true;
    }
    const int stop = sqrt(num)+1;
    for(int i = 2; i < stop; ++i){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int deep){
    if(EOP == true){
        return;
    }
    if(deep == 0){
        int sum = 0;
        int times = 1;

        for(int i = 0; i < out_size; ++i){
            sum*=10;
            sum+=out[i];
        }
        for(int i = out_size-2; i >= 0; --i){
            sum*=10;
            sum+=out[i];
        }


        if(sum >= a && sum <= b){
            is_prime(sum)?printf("%d\n", sum):0;
        }

        if(sum == 7){
            if(11 >= a && 11 <= b){
            printf("11\n");
            }
        }
        
        if(sum > b){
            EOP == true;
        }
        return;
    }

    for(int i = 0; i < 10; ++i){
        if(!(out_size==0&&data[i]==0)){
            out[out_size++] = data[i];
            dfs(deep-1);
            out[--out_size] = 0;
        }
    }
}

int main(){
    scanf("%d %d", &a, &b);
    int a_num = log10(a)+1;
    int b_num = log10(b)+1;

    a_num = ceil(a_num/2.0);
    b_num = ceil(b_num/2.0)/* + 1*/;

    for(int i = a_num; i <= b_num; ++i){
        dfs(i);
    }

    return 0;
}