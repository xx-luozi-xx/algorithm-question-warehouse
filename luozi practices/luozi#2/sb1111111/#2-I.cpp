#include <iostream>
using namespace std;
int main()
{
    int a, b, c, a1, b1, c1;
    cin >> a >> b >> c;
    a1 = min(min(a, b), c);
    b1 = a + b + c - min(min(a, b), c) - max(max(a, b), c);
    c1 = max(max(a, b), c);

    if (a1 + b1 > c1)
    {
        if (a1 * a1 + b1 * b1 == c1 * c1)
            cout << "Right triangle" << endl;
        else if (a1 * a1 + b1 * b1 > c1 * c1)
            cout << "Acute triangle" << endl;
        else
            cout << "Obtuse triangle" << endl;
        if (a == b || b == c || a == c)
            cout << "Isosceles triangle" << endl;
        if (a == b && b == c)
            cout << "Equilateral triangle" << endl;
    }
    else
        cout << "Not triangle" << endl;
    return 0;
}
//排了一下序，正确的

//因为排过序
//等腰可以写成 a==b || b==c
//等边可以写成 a==c

