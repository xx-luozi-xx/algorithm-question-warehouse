/*
题目描述

BMI 指数是国际上常用的衡量人体胖瘦程度的一个标准，其算法是 mh2h2m​，其中 mm 是指体重（千克），hh 是指身高（米）。不同体型范围与判定结果如下：

    小于 18.518.5：体重过轻，输出 Underweight；
    大于等于 18.518.5 且小于 2424：正常体重，输出 Normal；
    大于等于 2424：肥胖，不仅要输出 BMI 值（使用 cout 的默认精度），然后换行，还要输出 Overweight；

现在给出体重和身高数据，需要根据 BMI 指数判断体型状态并输出对应的判断。

对于非 C++ 语言，在输出时，请四舍五入保留六位有效数字输出，如果小数部分存在后缀 00，不要输出后缀 00。

请注意，保留六位有效数字不是保留六位小数。例如 114.5149114.5149 应该输出为 114.515114.515，9198.109198.10 应该输出为 9198.19198.1。
输入格式

共一行。

第一行，共 22 个浮点数，m,nm,n，分别表示体重（单位为 kgkg），身高（单位为 mm）。
输出格式

输出一行一个字符串，表示根据 BMI 的对应判断。特别地，对于 Overweight 情况的特别处理请参照题目所述。
输入输出样例
输入 #1

70 1.72

输出 #1

Normal
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float m, n;
	cin >> m >> n;
	float bmi = m / pow(n, 2);
	//* m/(n*n);
	if (bmi < 18.5)
	{
		cout << "Underweight";
	}
	else if (bmi >= 18.5 && bmi < 24)
	{
		cout << "Normal";
	}
	else
	{
		cout << bmi << endl;
		cout << "Overweight";
	}

}