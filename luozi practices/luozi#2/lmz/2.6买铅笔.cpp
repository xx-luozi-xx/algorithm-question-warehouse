/*
题目背景

NOIP2016 普及组 T1
题目描述

P 老师需要去商店买 nn 支铅笔作为小朋友们参加 NOIP 的礼物。她发现商店一共有 33 种包装的铅笔，不同包装内的铅笔数量有可能不同，价格也有可能不同。为了公平起 见，P 老师决定只买同一种包装的铅笔。

商店不允许将铅笔的包装拆开，因此 P 老师可能需要购买超过 nn 支铅笔才够给小朋友们发礼物。

现在 P 老师想知道，在商店每种包装的数量都足够的情况下，要买够至少 nn 支铅笔最少需要花费多少钱。
输入格式

第一行包含一个正整数 nn，表示需要的铅笔数量。

接下来三行，每行用 22 个正整数描述一种包装的铅笔：其中第 11 个整数表示这种包装内铅笔的数量，第 22 个整数表示这种包装的价格。

保证所有的 77 个数都是不超过 1000010000 的正整数。
输出格式

11 个整数，表示 P 老师最少需要花费的钱。
输入输出样例
输入 #1

57
2 2
50 30
30 27

输出 #1

54

输入 #2

9998
128 233
128 2333
128 666

输出 #2

18407

输入 #3

9999
101 1111
1 9999
1111 9999

输出 #3

89991
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b, c;
	double an, bn, cn;
	cin >> an >> a >> bn >> b >> cn >> c;

	int anum = ceil(n / an);
	int bnum = ceil(n / bn);
	int cnum = ceil(n / cn);
	int as = a * anum;
	int bs = b * bnum;
	int cs = c * cnum;
	for (int i = 0; i < 2; i++)
	{
		if (bs < as)
			swap(as, bs);
		if (cs < bs)
			swap(bs, cs);
	}
	cout << as;
}
