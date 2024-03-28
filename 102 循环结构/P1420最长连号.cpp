#include <stdio.h>
int main(){
    int n, max = 1, now = 1, a, b; scanf("%d",&n);    
    if(!n) return 0*printf("0");
    if(n==1) return 0*printf("1");
    scanf("%d",&b);
    for(int i = 0; i < n-1; i++){       
        a = b, scanf("%d",&b);
        if(b-a==1){
            now++;
        }else{
            now>max? max=now,now=1:0;
        }

    } 
    now>max? max=now,now=1:0;
    return 0*printf("%d",max);
}