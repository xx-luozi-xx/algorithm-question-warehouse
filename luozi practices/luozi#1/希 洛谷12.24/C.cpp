#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	double p,s,S;
	scanf("%lf%lf%lf",&a,&b,&c);

	p=(a+b+c)/2.0;
	s=p*(p-a)*(p-b)*(p-c);
	S=pow(s,1.0/2);
	
	printf("%.1f",S);
	return 0;
}
