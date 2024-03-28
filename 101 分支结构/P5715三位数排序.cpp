#include <cstdio>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a>b?a=a^b,b=a^b,a=a^b:0;
    b>c?b=b^c,c=b^c,b=b^c:0;
    a>b?a=a^b,b=a^b,a=a^b:0;
    printf("%d %d %d",a,b,c);
}