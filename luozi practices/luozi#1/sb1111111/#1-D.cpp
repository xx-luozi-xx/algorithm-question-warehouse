#include <iostream>
using namespace std;
int main()
{
    char a[5], b;
    for (int i = 0; (b = getchar()) != '\n'; i++)
        a[i] = b;
    for (int i = 4; i >= 0; i--)
        cout << a[i];
    system("pause");
    //原来这题数字都这么小的吗(笑)
    //不知道多大可以开大一点
    //char a[100];
    //字符数组可以看成字符串，c++支持字符串输入的操作，但是要确保空间足够
    // cin >> a;
    //倒叙输出可以通过strlen(a)获取字符串长度,在头文件<cstring>中
    // for(int i = strlen(a) - 1; i>=0; --i){
    //     cout << a[i];
    // }

    //等你学的更深入了，再跟你讲字符数组操作和c++字符串string类型
}