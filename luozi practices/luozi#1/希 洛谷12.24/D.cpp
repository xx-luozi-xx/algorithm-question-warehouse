#include<stdio.h>
int main1()
{
	double num,ans=0;
	scanf("%lf",&num);
	int temp=num*10;
	while(temp)
	{
		ans=(temp%10)+ans*10;
		temp/=10;
	}
	ans/=1000.0;
	printf("%.3lf",ans);
	return 0;
}

#include <string.h>
//* 字符串反向输出
char str0[50];
int main(){
	char str[50]={};
	char str1[50]={0};
	char str2[50];//!未知

	scanf("%s", str);

	//*"123456";"123456\0";c[strlen(c)];
	for(int i = strlen(str); i >= 0; --i){
		printf("%c", str[i]);
	}
	return 0;
}
