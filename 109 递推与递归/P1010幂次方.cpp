#include <stdio.h>

void depower(int n){
    if(n == 0){
        printf("0");
        return;
    }else if(n == 1){
        return;
    }
    bool pow[20]{};
    int ptr = 0;
    while(n){
        if(n%2 == 1){
            pow[ptr] = true;
            --n;
        }
        n/=2, ++ptr;
    }
    bool first = true;
    for(int i = ptr-1; i >= 0; --i){
        if(pow[i]){
            first?first = false:printf("+");
            printf("2");
            i != 1?printf("("):0;
            depower(i);
            i != 1?printf(")"):0;
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    if(n == 1){
        printf("2(0)");
        return 0;
    }
    depower(n);
    return 0;
}