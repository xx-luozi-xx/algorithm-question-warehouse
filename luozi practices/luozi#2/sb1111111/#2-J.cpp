#include <iostream>
using namespace std;
int main()
{
    char ISBN[13];
    int sum = 0;
    cin >> ISBN;
    for (int i = 0, j = 0; i <= 11; i++, j++)
    {
        if (ISBN[i] != '-')
            sum += (ISBN[i] - '0') * (j + 1);
        else
            j--;
    }
    if ((sum % 11 == ISBN[12] - '0') || (sum % 11 == ISBN[12] - 78))
        cout << "Right" << endl;
    else if (sum % 11 != 10)
    {
        for (int i = 0; i <= 11; i++)
            cout << ISBN[i];
        cout << sum % 11 << endl;
    }
    else
    {
        for (int i = 0; i <= 11; i++)
            cout << ISBN[i];
        cout << "X" << endl;
    }
    return 0;
}
//写的挺好
/*
    就是注意一个细节
    C/C++在数据处理上容易溢出
    因为往往int 甚至 unsigned long long的最大值都装不下
    (当然这题没有溢出)

    所以只要是出现累乘和。阶乘或者一些很大的递推式
    就要考虑溢出
    溢出处理有两种做法
    1.题目要求最终结果取模的(比如这题模11),那么在sum的每一步运算都会%=11，随时防止数据溢出
    2.要求精确输出的，采用高精度策略(之后会练到，就是用一个数组表示一个数，手动处理运算进位等)
*/