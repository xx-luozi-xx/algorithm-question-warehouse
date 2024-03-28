#include <iostream>
using namespace std;
int main()
{
    int n, x, num = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j /= 10)
        {
            if (j % 10 == x)
                num++;
        }
    }
    cout << num << endl;
    return 0;
}