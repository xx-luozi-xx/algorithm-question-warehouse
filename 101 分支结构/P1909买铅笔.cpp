#include <cstdio>
int main(){
    int n, a, b, last=__INT_MAX__,i=0;
    scanf("%d",&n);
    while(++i<=3){
        scanf("%d %d",&a,&b);
        (n/a+!!(n%a))*b<last?last=(n/a+!!(n%a))*b:0;
    }
    printf("%d",last);
}