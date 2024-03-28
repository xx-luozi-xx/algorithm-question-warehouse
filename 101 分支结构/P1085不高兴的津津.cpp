#include <cstdio>
int main(){
    int day=0,big=0,a=0,b=0,c=0,i=0;
    while(++i<=7){
        scanf("%d %d",&a,&b),a+=b;
        a>c?day=i,c=a:0;
    }
    printf("%d",c>8?day:0);
}