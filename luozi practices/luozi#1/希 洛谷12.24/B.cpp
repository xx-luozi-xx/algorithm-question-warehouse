#include<stdio.h>
#include<math.h>  //!luozi
#define PI 3.1415   //!预编译命令不需要分号

int main()
{
    int h,r;
    scanf("%d%d",&h,&r);
    int n=1;
    int v=h*r*r*PI;
    while(n*v<20000) {
    	n++;
	}
//*    O(n)

    n = ceil(20000/(h*r*r*PI));
//*    O(1)
/*
    floor()下取整
    round()四舍五入
    ceil()上取整

    (int)()截后取整

    1.5  2  1  1
    -1.5 -1 -2  -1
    */
	printf("%d",n);
	return 0;
}
