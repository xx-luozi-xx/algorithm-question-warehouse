#include <iostream>
using namespace std;
int main()
{
    int n, num[100], max, min;
              0x7fffffff;0x80000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    min = num[0];
    max = num[0];
    for (int i = 0; i < n; i++)
    {
        if (num[i] < min)
            min = num[i];
        if (num[i] > max)
            max = num[i];
    }
    cout << max - min << endl;
    return 0;
}