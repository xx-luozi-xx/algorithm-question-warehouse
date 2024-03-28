#include <iostream>
using namespace std;
int main()
{
    int y, m;
    cin >> y >> m;
    if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (m == 2))
        cout << 29 << endl;
    else if (m == 2)
        cout << 28 << endl;
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        cout << 31 << endl;
    else
        cout << 30 << endl;
    return 0;
}
/*
挺好挺标准的，代码十分工整，可读性非常高，写工程就喜欢这样的代码
*/