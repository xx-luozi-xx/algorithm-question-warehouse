#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int h, r;
    cin >> h >> r;
    double v = 3.14 * r * r * h;
    //3.14竟然过了，一般可以把精度弄高一点，比如3.1415926
    cout << ceil(20000 / v) << endl;
    system("pause");
}