#include <stdio.h>
#define ull unsigned long long

ull x[20],a,b,box;
int main(){
    scanf("%llu%llu",&a,&b);
    for(int i=a;i<=b;i++){
        box=i;
        do{
            x[box%10]++;
        }while(box/=10);
    }
    for(int i=0;i<10;i++){
        printf("%llu ",x[i]);
    }
    return 0;
}
