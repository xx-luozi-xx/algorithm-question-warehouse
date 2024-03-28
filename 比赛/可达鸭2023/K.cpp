#include <stdio.h>
const int MAX_SIZE_ = 100;

int n;

int main(){
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int input;
        scanf("%d", &input);;
        sum^=input;
    }
    if(sum == 0){
        printf("%lld", 1ll<<(long long)n);
    }else{
        printf("0");
    }
    return 0;
}