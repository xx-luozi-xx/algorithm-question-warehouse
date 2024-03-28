#include<stdio.h>
int main(){
    int n,m=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            printf("%d%d",m/10,m%10);
            //m<10?printf("0%d", m):printf("%d", m);
            m=m+1;
        }
        printf("\n");
    }
    return 0;
}