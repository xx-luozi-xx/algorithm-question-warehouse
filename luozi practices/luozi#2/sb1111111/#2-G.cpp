#include <iostream>
#include <iomanip>
using namespace std;
#define PRICE1 0.4463
#define PRICE2 0.4663
#define PRICE3 0.5663
int main()
{
    int use;
    double price;
    cin >> use;
    if (use <= 150)
        price = use * PRICE1;
    else if (use <= 400)
        price = 150 * PRICE1 + (use - 150) * PRICE2;
    else
        price = 150 * PRICE1 + 250 * PRICE2 + (use - 400) * PRICE3;
    cout << fixed << setprecision(1) << price << endl;
    return 0;
}
//工程写法非常标准！
//输出格式控制及不下来可以考虑printf();