#include <iostream>
using namespace std;
int main()
{   //挺好，就是变量命名有点高血压
    
    int a, b, c, d, e, f, total;
    cin >> a >> b >> c >> d;
    total = c * 60 + d - (a * 60 + b);
    e = total / 60;
    f = total % 60;
    cout << e << " " << f << endl;
    system("pause");
}