#include <iostream>
using namespace std;
int main()
{
    char a;
    /* 也可以这么写，可以研究一下'a'或者'A',是啥，即单引号内+字符表示什么
    cin << a;
    a += -'a' + 'A';
    cout << a;
    */
    a = getchar();
    putchar(a - 32);
    system("pause");


}