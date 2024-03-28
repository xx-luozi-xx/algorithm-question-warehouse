#include <cstdio>
int main(){
    int y,m;
    scanf("%d %d",&y,&m);
    m>7?printf("%d",30+!(m&1)):0;
    m<8&&m!=2?printf("%d",30+m&1):0;
    m==2?printf("%d",28 + (!(y%4)&&y%100||!(y%400))):0;
}