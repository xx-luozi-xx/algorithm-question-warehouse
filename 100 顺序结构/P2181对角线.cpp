#include <stdio.h>
#define ull unsigned long long
int main(){
  ull a;
  scanf("%llu", &a);
  //  printf("%d %d %d ", a, gg(a), cc(a));
  printf("%llu", a*(a-1)/2*(a-2)/3*(a-3)/4);
}
