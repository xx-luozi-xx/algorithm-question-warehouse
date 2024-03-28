/*
题目描述

夏天到了，各家各户的用电量都增加了许多，相应的电费也交的更多了。小玉家今天收到了一份电费通知单。小玉看到上面写：据闽价电 [2006]27 号规定，月用电量在 150150 千瓦时及以下部分按每千瓦时 0.44630.4463 元执行，月用电量在 151∼400151∼400 千瓦时的部分按每千瓦时 0.46630.4663 元执行，月用电量在 401401 千瓦时及以上部分按每千瓦时 0.56630.5663 元执行;小玉想自己验证一下，电费通知单上应交电费的数目到底是否正确呢。请编写一个程序，已知用电总计，根据电价规定，计算出应交的电费应该是多少。
输入格式

输入一个正整数，表示用电总计（单位以千瓦时计），不超过 1000010000。
输出格式

输出一个数，保留到小数点后 11 位（单位以元计，保留到小数点后 11 位）。
输入输出样例
输入 #1

267

输出 #1

121.5
*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << fixed << setprecision(1);
	if (n < 151)
		cout << n * 0.4463;
	else if (n > 150 && n < 401)
		cout << (150 * 0.4463 + (n - 150) * 0.4663);
	else
		cout << (150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663);
}

#include <iostream>
#include <iomanip>
using namespace std;
#define PRICE1 0.4463
#define PRICE2 0.4663
#define PRICE3 0.5663
int main()
{
    int use;
    double price;
    cin >> use;
    if (use <= 150)
        price = use * PRICE1;
    else if (use <= 400)
        price = 150 * PRICE1 + (use - 150) * PRICE2;
    else
        price = 150 * PRICE1 + 250 * PRICE2 + (use - 400) * PRICE3;
    cout << fixed << setprecision(1) << price << endl;
    return 0;
}
//工程写法非常标准！
//输出格式控制及不下来可以考虑printf();