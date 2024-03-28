#include <iostream>
#include <algorithm> //!算法库
using namespace std;
#define MAX_SIZE (5000 + 5)

int num[MAX_SIZE][MAX_SIZE];
int main()
{
    2 * MAX_SIZE;
    int n, jin_wei, len = 1;
    cin >> n;
    num[1][1] = 1, num[2][1] = 2;
    for (int i = 3; i <= n; i++)
    {
        jin_wei = 0;
        for (int j = 1; j <= len; j++)
        {
            num[i][j] = num[i - 1][j] + num[i - 2][j] + jin_wei;
            jin_wei = num[i][j] / 10;
            num[i][j] %= 10;
        }
        if (jin_wei)
            num[i][++len] = jin_wei;
    }

    bool start = false;
    for (int i = MAX_SIZE - 1; i >= 1; i--)
    {
        if (num[n][i] != 0 || start == true)
        {
            start = true;
            cout << num[n][i];
        }
    }

    /* 另一种输出
    for (len = MAX_SIZE - 1; num[n][len] == 0; len--);
    for (int i = len; i >= 1; i--)
    {
        cout << num[n][i];
    }
    */

    return 0;
}