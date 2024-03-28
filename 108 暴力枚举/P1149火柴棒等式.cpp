#include <stdio.h>

int single_cnt[10] = {6,2,5,5,4,5,6,3,7,6};
int cnt(int a){
    if(a == 0){
        return single_cnt[0];
    }
    int ret = 0;
    while(a!=0){
        ret += single_cnt[a%10];
        a/=10;
    }
    return ret;
}
int main(){
    int out = 0;
    int a;
    scanf("%d",&a);
    a-=4;

    for(int A = 0; A < 1000; ++A){
        for(int B = A; B < 1000; ++B){
            int C = A + B;
            if(cnt(A)+cnt(B)+cnt(C)==a){
                out++;
                if(A!=B){
                    out++;
                }
            }
        }
    }
    printf("%d",out);
    return 0;
}