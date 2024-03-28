#include <stdio.h>
#include <math.h>   //abs()
#define MAX_SIZE (1000+30)

int n;
int num[MAX_SIZE];
int sub[MAX_SIZE];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", num+i);
    }
    for(int i = 0; i < n-1; ++i){
        int sub_ = abs(num[i]-num[i+1]);
        if(sub_ <= 0 || n <= sub_ || sub[sub_] != 0){
            printf("Not jolly");
            return 0;
        }else{
            sub[sub_] = 1;
        }
    }
    printf("Jolly");
    return 0;
}
