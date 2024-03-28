#include <iostream>
#include <cmath>
using namespace std;
int num_len(double num)
{
    int int_num = num, num_len;
    for (num_len = 0; int_num != 0; num_len++)
    {
        int_num /= 10;
    }
    //return 可以不用括号
    return (num_len);
}
int main()
{
    double a, b, c, p, s;
    cin >> a >> b >> c;
    p = 0.5 * (a + b + c);
    s = round(sqrt(p * (p - a) * (p - b) * (p - c)) * 10) / 10.0;
    //通常浮点(包括双精度型)不能直接比较相等，因为浮点存储不准确，用做差小于某很小的值来表示相等
    int s3 = s;
    if (s3 == s)
        cout << s << ".0" << endl;
    else
    {
        if (num_len(s) >= 6)//这个分支怪怪的，四舍五入处理后
        {
            int s1 = s, s2 = s * 10;
            cout << s1 << "." << s2 % 10 << endl;
        }
        else
            cout << s << endl;
    }
    system("pause");
}
/*
这题主要是在输出格式控制上
可以学一下两种操作
1，搜一下C++输出流格式控制
2，研究一下C语言printf()函数，如这题可以直接printf("%.1f",s);[这个格式控制会自己5舍六入。不知道为什么过了，测试点数据不够强吧]


*/