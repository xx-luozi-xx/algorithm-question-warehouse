#include<stdio.h>
int main(){
    int n,m,a=0,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<(n+1);i++){
        b=i;
        while(b>0){
            if(m==b%10)a=a+1;
            b=b/10;
        }
    }
    printf("%d",a);
    return 0;
}