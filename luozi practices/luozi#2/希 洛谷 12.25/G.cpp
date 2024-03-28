#include<stdio.h>
#include<math.h>

int main()
{
	int power;
	double money;
	scanf("%d",&power);
	if(power<=150)
		money=0.4463*power;
	else if(power>150&&power<400)
		money=0.4463*150+(power-150)*0.4663;
	else
		money=0.4463*150+250*0.4663+(power-400)*0.5663;
	printf("%.1f",money);	
}
