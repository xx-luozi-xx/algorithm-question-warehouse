#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
//挺好，对于布尔值可以直接输出0/1，所以你可以直接 cout << (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);完事