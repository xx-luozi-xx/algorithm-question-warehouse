A:
#include<iostream>
using namespace std;

int main()
{
	char c;
	cin >> c;
	cout << char(c - 32);
    //记不住ascII可以这样操作：
    //小写转大写： c += (-'a'+'A');
    //大写转小写： c += (-'A'+'a');
}
B:
#include<iostream>
#include<cmath>
using namespace std;

#define pi 3.1415926535
//宏定义操作很好，这种常量定义方法很规范
//习惯上我们所有的宏定义（有时包括常量、枚举），名称习惯上定义为大写
//如 #define PI 3.1415926535
int main()
{
	int h, r;
	cin >> h >> r;
	cout << ceil(20000 / (pi * r * r * h));
    //常用取整函数有三个，可以记一下
    //ceil上取整
    //round四舍五入
    //floor下取整
    //补充一个printf("%.1f",3.15);
    //printf中保留n位小数是5舍6入，上面那行会输出3.1
}
C:
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(1) << float(sqrt(((a + b + c) / 2.0) * (((a + b + c) / 2.0) - a) * (((a + b + c) / 2.0) - b) * (((a + b + c) / 2.0) - c)));
    //公式表示十分正确，代码很简短
    //如果想提高可读性可以这样尝试
    /*
    float q = (a+b+c)/2;    
    */
   //再把q带人式子，这要在长代码中方便debug以及调整

   //同时，C++输出流的格式控制操作我也记不下来
   //如果真记不下来，可以考虑printf（）函数，这玩意格式控制比较直观，可以搜一下
}
D:
#include<iostream>
using namespace std;

int main()
{
	char c[6] = { 0 };
    //初始化为0的写法很标准，记得栈中定义的变量需要初始化，系统可能留下的脏数据
    /*初始化识别流程：
    将花括号成为初始化列表，对于数组中的每一个值，按顺序初始化, 初始化列表值不住的补零(或者调用默认构造函数)
    所以char c[6] = {0};的流程为：
    初始化列表自动补齐为{0,0,0,0,0,0}，再赋值。
    于是初始化数组我们也可以直接
    char c[6] = {};

    同时关于默认构造函数，基础数据类型也是有默认构造函数的，比如
    int() 表示 0
    char() 也是 0
    */
	for (int i = 0; i < 5; i++)
	{
		cin >> c[i];
	}
	for (int i = 5; i > 0; i--)
	{
		cout << c[i - 1];
	}
    //这一题反向输出其实不适合用定长数据
    //考虑给出任易长度的字符串，怎么反向输出？
    /*
    提示，你需要熟悉#include <string.h>中的函数，如strlen()的使用方法及工作原理

    当然，之后的练习会有涉及字符串的专题的
    */
}
E：
#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	if (d < b)
	{
		f = d + 60 - b;
		e = c - a - 1;
	}
	else
	{
		f = d - b;
		e = c - a;
	}
	cout << e << " " << f;
    //这题写的挺好，题目本质是减法的退位
    //拓展情况可以考虑数组表示多位数，然后做减法怎么进行退位
}
F:
#include<iostream>
#include<cmath>
using namespace std;

void time(int, int);//我给你把函数搬到下面去，这样可以按顺序看

int main()
{
	int s, v, h, m, _h, _m;
	cin >> s >> v;

	_h = int((s / v + 10) / 60);
	_m = ((int)ceil((double)s / v)+10) % 60;
    //直到这里都挺好，下面代码开始有点冗余了

	if (_m == 60)//_m模过60了，这里就不会 >= 60，事实上前面两句已经进位完备了。
	{
		_m = 0;
		_h++;
	}

	time(_h, _m);//看下面

}

void time(int _h, int _m)
{
	if (_h < 8)//首先，对于if的结构和括号的缩进我们可以试着改个习惯
    //这样看起来会清晰些，往下翻，看改版
	{
		if (_m < 51)
		{
			cout << 0 << (7 - _h) << ":" << 60 - _m;
		}
		else
		{
			cout << 0 << (7 - _h) << ":" << 0 << 60 - _m;
		}
	}
	else
	{
		if (_h < 22)
		{
			if (_m < 51)
			{
				cout << 31 - _h << ":" << 60 - _m;
			}
			else
			{
				cout << 31 - _h << ":" << 0 << 60 - _m;
			}
			
		}
		else
		{
			if (_m < 51)
			{
				cout << 0 << 31 - _h << ":" << 60 - _m;
			}
			else
			{
				cout << 0 << 31 - _h << ":" << 0 << 60 - _m;
			}
		}
	}
}

//我只修改了括号的位置以及else后紧跟if我删去了一层括号
//这样的结构表述可以理解为：
/*
    if(A){

    }else if(B){

    }else if(C){

    }else{

    }
是4个并列语句，程序 会且仅会 执行某一分支
而且代码比较紧凑，容易对应条件和执行块，便于查看和debug


*/
void time(int _h, int _m){//这样看起来就很清晰了
	if (_h < 8)	{
		if (_m < 51){
			cout << 0 << (7 - _h) << ":" << 60 - _m;
		}else{
			cout << 0 << (7 - _h) << ":" << 0 << 60 - _m;
		}
	}else if (_h < 22){
        if (_m < 51){
            cout << 31 - _h << ":" << 60 - _m;
        }else{
            cout << 31 - _h << ":" << 0 << 60 - _m;
        }			
	}else if (_m < 51){
        cout << 0 << 31 - _h << ":" << 60 - _m;
    }else{
        cout << 0 << 31 - _h << ":" << 0 << 60 - _m;
    }
}
//分类讨论是针对补0的情况，讨论是正确的，但是对于补零的情况你可以参考这种写法：

/*
给定一个整数n(0<= n< 9999)，要求输出n
确保输出四位数，不足4位的前面补0

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    // 注意下面是多个if，不是else if
    if(n<10){
        printf("0");
    }
    if(n<100){
        print("0");
    }
    if(n<1000){
        printf("0");
    }
    printf("%d", n);
}
//当然也可以采用else if
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    if(n<10){
        printf("000");
    }else if(10<=n&&n<100){
        print("00");
    }else if(100<=n&&n<1000){
        printf("0");
    }
    printf("%d", n);
}
//再一种是使用问号？表达式，等价于多个if，（不是else if）
//我个人比较喜欢用，因为在短小分支上很很方便

问好表达式：
(条件)?(值1):(值2);
条件为真返回值1，条件不真返回值2

等价于：
if(条件){
    return 值1;
}else{
    return 值2；
}

用在printf()上是因为printf()也是具有返回值的函数，返回成功输出的字符数。
我们要的不是他的返回值，而是执行过程，所以返回什么无所谓。

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    n<10?printf("0"):0;
    n<100?print("0"):0;
    n<1000?printf("0"):0;
    printf("%d", n);
}

*/

我翻到了我以前写的，可以参考：
#include <cstdio>
#include <cmath>
int main(){
  int s, v, t;
  scanf("%d %d",&s,&v);
  t = ceil(double(s)/v) + 10;
  //获取耗费小时和分钟。
  int h,m;
  h = t/60, m = t%60;
  //计算应该输出的小时和分钟
  m = (m == 0? 0 : (h++,60-m));//里面有个逗号表达式，返回值是最右边的，执行过程是从左到右
  h = (8-h >= 0? 8-h : 8-h+24);
  //补零输出
  h < 10 ? printf("0"):0;
  printf("%d:",h);
  m < 10 ? printf("0"):0;
  printf("%d",m);
}


//最后就是main()也要记得加return 0，嗯，不过打题无所谓