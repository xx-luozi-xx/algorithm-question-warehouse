/*
题目描述

给出三条线段 a,b,ca,b,c 的长度，均是不大于 1000010000 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

    如果三条线段不能组成一个三角形，输出Not triangle；
    如果是直角三角形，输出Right triangle；
    如果是锐角三角形，输出Acute triangle；
    如果是钝角三角形，输出Obtuse triangle；
    如果是等腰三角形，输出Isosceles triangle；
    如果是等边三角形，输出Equilateral triangle。

如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。
输入格式

输入 3 个整数 aa、bb 和 cc。
输出格式

输出若干行判定字符串。
输入输出样例
输入 #1

3 3 3

输出 #1

Acute triangle
Isosceles triangle
Equilateral triangle

输入 #2

3 4 5

输出 #2

Right triangle

输入 #3

6 10 6

输出 #3

Obtuse triangle
Isosceles triangle

输入 #4

1 14 5

输出 #4

Not triangle

说明/提示

当两短边的平方和大于一长边的平方，说明是锐角三角形。

当两短边的平方和等于一长边的平方，说明是直角三角形。

当两短边的平方和小于一长边的平方，说明是钝角三角形。

*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 2; i++)
    {
        if (b < a)
            swap(a, b);
        if (c < b)
            swap(b, c);
    }//a b c边长递增
    if ((a + b > c) && (a + c > b) && (a + b > c))
    {
        if (a * a + b * b == c * c)
        {
            cout << "Right triangle" << endl;
            if (a == b)
                cout << "Isosceles triangle" << endl;
        }
        else if (a * a + b * b > c * c)
        {
            cout << "Acute triangle" << endl;
            if (a == b)
            {
                cout << "Isosceles triangle" << endl;
                if (a == b && b == c)
                    cout << "Equilateral triangle" << endl;
            }
        }
        else
        {
            cout << "Obtuse triangle" << endl;
            if (a == b)
                cout << "Isosceles triangle" << endl;
        }
    }
    else
        cout << "Not triangle";
}