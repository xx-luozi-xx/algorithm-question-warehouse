/*
题目描述

给出三个整数 a,b,c(0≤a,b,c≤100)a,b,c(0≤a,b,c≤100)，要求把这三位整数从小到大排序。
输入格式

输入三个整数 a,b,ca,b,c，以空格隔开。
输出格式

输出一行，三个整数，表示从小到大排序后的结果。
输入输出样例
输入 #1

1 14 5

输出 #1

1 5 14

输入 #2

2 2 2

输出 #2

2 2 2
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{	//*打表
	int month[14] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m;
	cin >> y >> m;
	if (y % 4 == 0)
	{
		if (y % 100 == 0 && y % 400 == 0)
		{
			if (m == 2)
				cout << 29;
			else
				cout << month[m];
		}
		else if (y % 100 == 0 && y % 400 != 0)
		{
			cout << month[m];
		}
		else
		{
			if (m == 2)
				cout << 29;
			else
				cout << month[m];
		}
	}
	else
		cout << month[m];

}