#include <iostream>
using namespace std;
int main()
{
    int x, n, sum = 0;
    cin >> x >> n;
    for (; n > 0; n--)
    {
        if (x != 6 && x != 7)
            sum += 250;
        (x %= 7)++;
    }
    cout << sum << endl;
    return 0;
}
//这做法是纯模拟了，时间复杂度O(n)
//想想有没有O(1)的解法？

//时间复杂度的意义是让代码跑的更快/
/*比如你现在是O(n)线性的算法
对于给定的n，需要正比于n的时间才能跑完
要是它给一个n非常大，比如10^15就会超时了

但是这题有O(1)的算法，就是对于给定的无论如何
都能在常数倍的时间下跑完
*/