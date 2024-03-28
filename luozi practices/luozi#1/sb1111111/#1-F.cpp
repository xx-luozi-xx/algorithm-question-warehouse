#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double s, v;
    int time, time1, time2;
    cin >> s >> v;
    time = 8 * 60 - ceil(s / v) - 10;
    if (time < 0)
        time += 24 * 60;
    time1 = time / 60;
    time2 = time % 60;
    if (time1 < 10 && time2 < 10)
        cout << "0" << time1 << ":0" << time2 << endl;
    else
    {
        if (time1 < 10)
            cout << "0" << time1 << ":" << time2 << endl;
        else
        {
            if (time2 < 10)
                cout << time1 << ":0" << time2 << endl;
            else
                cout << time1 << ":" << time2 << endl;
        }
    }
    system("pause");
}//挺好，就是其实不需要每题都加system(),这个看着挺怪的
//另一个，main函数要养成加return 0的好习惯，保持函数规整合理性。
//main返回值在一些工程会用到