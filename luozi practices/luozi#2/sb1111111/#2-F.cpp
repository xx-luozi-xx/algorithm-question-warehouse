#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double n, p_num, p_price, price;
    int min = 2147483647;
    //! luozi
    //*记不下来这个数？可以考虑下面两种写法   
    min = 0x7fffffff;
    min = __INT_MAX__;
    /*
        三种写法等价
        __INT_MAX__不解释，是内部定义的
        0x7fffffff是怎么回事呢？
        首先int存储4个字节，每个字节8位
        0x表示后面是16进制数，每两位16进制数对应一个字节(8位)

        int的内部解析是：最高位是符合位，其他是数据位
        0x7fffffff就让最高位是0，其他的都是1，就是int能表示的最大的数



        注意：整数类型(int ,unsigned, long long, unsigned long long, char)除符号位之外，存储的都是补码。
        而整数二进制数的补码就是它本身，上面因为最大值是正的所以没强调这一点。
        之所以提及这一点是因为0xffffffff并不是负的最小，而是-1。负的最小应该是0x80000000.具体搜搜补码。
    */
    int int_min = (int)0x80000000;//0x的表示默认是unsigned
    //! end luozi
    
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {
        cin >> p_num >> p_price;
        price = ceil(n / p_num) * p_price;
        if (price < min)
            min = price;
    }
    cout <<min << endl;
    return 0;
}