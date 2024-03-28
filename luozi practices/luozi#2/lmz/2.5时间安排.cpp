/*
题目描述

津津上初中了。妈妈认为津津应该更加用功学习，所以津津除了上学之外，还要参加妈妈为她报名的各科复习班。另外每周妈妈还会送她去学习朗诵、舞蹈和钢琴。但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。
输入格式

输入包括 77 行数据，分别表示周一到周日的日程安排。每行包括两个小于 1010 的非负整数，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。
输出格式

一个数字。如果不会不高兴则输出 00，如果会则输出最不高兴的是周几（用 1,2,3,4,5,6,71,2,3,4,5,6,7 分别表示周一，周二，周三，周四，周五，周六，周日）。如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。
输入输出样例
输入 #1

5 3
6 2
7 2
5 3
5 4
0 4
0 6

输出 #1

3
*/
#include<iostream>
#include<cmath>
using namespace std;

struct everyday
{
	int day;
	int hour;
	//* 常函数和常对象， 常对象只能调用常函数
	//* “const”确保不会修改值
	//* 虽然我们很少主动声明常量，但是在传参数的时候，可能变成常对象
	bool operator>(const everyday& e) const
	{
		return hour > e.hour;
	}
};
/*
void func(const everyday& lhs, const everyday& rhs){
	lhs>rhs;
}
everyday d_1, d_2;
int a =	d_1 > d_2;
int b = (func(d_1, d_2) , 0);

*/

void maxnum(everyday* c)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			if (c[j] > c[j + 1])
				swap(c[j], c[j + 1]);
		}
	}
}

int main()
{	//*离线操作 （全输入，再处理）
	int a[8], b[8];
	everyday c[7];
	for (int i = 0; i < 7; i++)
	{
		cin >> a[i] >> b[i];
		c[i].hour = a[i] + b[i];
		c[i].day = i + 1;
	}
	maxnum(c);
	if (c[6].hour <= 8)
		cout << 0;
	else
	{
		for (int i = 0; i < 7; i++)
		{
			if (c[i].hour == c[6].hour)
			{
				cout << c[i].day;
				break;
			}
		}

	}
	return 0; //!luozi
}

int main1(){
	//*在线操作（边输入，边处理）
	everyday max;
	everyday box;//* temp

	for(7次){
		cin >> box;
		box > max? max = box : 0 ;
		//* max = MAX(max, box);
	}
	cout << max;
}
