#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a, b), c) << " " << a + b + c - min(min(a, b), c) - max(max(a, b), c) << " " << max(max(a, b), c);
    return 0;
}
/*
嗯，这个暴力输出是我没想到的
进一步可以考虑排序算法
*/