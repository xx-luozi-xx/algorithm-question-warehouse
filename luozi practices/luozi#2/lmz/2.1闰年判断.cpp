//输入一个年份，判断这一年是否是闰年，如果是输出 11，否则输出 00。
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 4 == 0)
	{
		if (n % 100 == 0 && n % 400 == 0)
		{
			cout << 1;
		}
		else if (n % 100 == 0 && n % 400 != 0)
		{
			cout << 0;
		}
		else
			cout << 1;
	}
	else
		cout << 0;
	return 0;//! luozi
		
	//* if((y%4==0&&y%100!=0)||y%400==0)
}