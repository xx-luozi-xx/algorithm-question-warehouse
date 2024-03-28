#include <stdio.h>
int main(){
    int n,p=1;scanf("%d",&n);
    while(n--){
        for(int i=n+1;i--;)
            p<10?printf("0%d",p++):printf("%d",p++);
        printf("\n");
    }
}