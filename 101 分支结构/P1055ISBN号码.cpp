#include <stdio.h>
int main(){
    char a[50]={0};
    int x=0,k=0;
    scanf("%s",a);
    for(char i=1;i<=9;i++){
        a[k]=='-'?x+=(a[++k]-'0')*i:x+=(a[k]-'0')*i,k++;    
    }
    x%11==10?x='X':x=x%11+'0';
    x==a[12]?printf("Right"):(a[12]=x,printf("%s",a));
}