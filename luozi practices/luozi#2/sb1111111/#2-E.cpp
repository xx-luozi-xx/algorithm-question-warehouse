#include <iostream>
using namespace std;
int main()
{
    int hr1, hr2, day, max = 0;
    for (int i = 1; i <= 7; i++)
    {
        cin >> hr1 >> hr2;
        if ((hr1 + hr2 > 8) && (hr1 + hr2 > max))
        {
            max = hr1 + hr2;
            day = i;
        }
    }
    cout << day << endl;
    return 0;
}
/*
嗯，取最大的策略的写法很规范
*/