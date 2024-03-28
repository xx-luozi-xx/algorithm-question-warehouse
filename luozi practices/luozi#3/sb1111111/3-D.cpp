#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define MAX_LEN 500 + 5
#define NONE -1
int main()
{
    string a, b;
    int len_a, len_b, len, temp, reverse_a[MAX_LEN], reverse_b[MAX_LEN], result[MAX_LEN];
    // 初始化result数组的值全为-1
    for (int i = 0; i < MAX_LEN; i++)
    {
        result[i] = NONE;
    }

    cin >> a >> b;
    len_a = a.length(), len_b = b.length();
    string zero(fabs(len_a - len_b), '0');
    if (len_a > len_b)
        b = zero + b;
    else
        a = zero + a;

    len = a.length();
    result[0] = 0;
    for (int i = 0; i < len; i++)
    {
        // 逆序a,b
        reverse_a[i] = a[len - i - 1] - '0';
        reverse_b[i] = b[len - i - 1] - '0';
        // 进位
        temp = result[i] + reverse_a[i] + reverse_b[i];
        result[i] = temp % 10;
        result[i + 1] = temp / 10;
        // 处理数字开头可能的0
        if (i == len - 1 && result[i + 1] == 0)
            result[i + 1] = NONE;
    }

    for (int i = 0; i < MAX_LEN; i++)
    {
        // 只输出有效的数字
        if (result[MAX_LEN - i - 1] != NONE)
            cout << result[MAX_LEN - i - 1];
    }
    return 0;
}