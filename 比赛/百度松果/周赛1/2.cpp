// https://www.matiji.net/exam/brushquestion/27/3181/1DC60EA6DF83A333301CFFE1407FBA59
#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int cnt = 0;
    while(n){
        cnt ++;
        if(n&1){
            n--;
        }else{
            n>>=1;
        }
    }
    printf("%d", cnt);
    return 0;
}

