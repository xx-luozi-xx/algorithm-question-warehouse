#include <cstdio>
#include <cmath>
int main(){
  int s, v, t;
  scanf("%d %d",&s,&v);
  t = ceil(double(s)/v) + 10;
  int h,m;
  h = t/60, m = t%60;
  m = (m == 0? 0 : h++,60-m);
  h = (8-h >= 0? 8-h : 8-h+24);
  h < 10 ? printf("0"):0;
  printf("%d:",h);
  m < 10 ? printf("0"):0;
  printf("%d",m);
}
