#include <iostream>
using namespace std;
int main()
{
    double m, h, BMI;
    cin >> m >> h;
    BMI = m / (h * h);
    if (BMI < 18.5)
        cout << "Underweight" << endl;
    else if (BMI < 24)
        cout << "Normal" << endl;
    else
        cout << BMI << "\nOverweight" << endl;
    return 0;
}
/*最后的else里头写{
    cout << BMI << endl;
    cout << "Overweight" << endl;
}
会更标准点

*/