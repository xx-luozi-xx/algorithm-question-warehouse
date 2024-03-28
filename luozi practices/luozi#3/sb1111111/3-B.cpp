#include <iostream>
using namespace std;
int main()
{
    int k, n;
    double sum = 0;
    cin >> k;
    for (n = 1; sum <= k; n++)
    {
        sum += 1.0 / n;
    }
    cout << n - 1 << endl;
    return 0;
}