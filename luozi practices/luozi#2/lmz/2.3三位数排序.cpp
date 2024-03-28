/*
题目描述

给出三个整数 a,b,c(0≤a,b,c≤100)a,b,c(0≤a,b,c≤100)，要求把这三位整数从小到大排序。
输入格式

输入三个整数 a,b,ca,b,c，以空格隔开。
输出格式

输出一行，三个整数，表示从小到大排序后的结果。
输入输出样例
输入 #1

1 14 5

输出 #1

1 5 14

输入 #2

2 2 2

输出 #2

2 2 2
*/
#include<iostream>
using namespace std;

int main0()
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 2; i++)
	{
		if (b < a)
			swap(a, b);
		if (c < b)
			swap(b, c);
	}
	cout << a << " " << b << " " << c;
}

#include <algorithm>
using namespace std;
int main1(){
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
	}
	sort(arr, arr+3);//*默认升序, 默认用 < 排序
	//*  [         )

}

int main2(){
	//*负数降序
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
		arr[i]*=-1;
	}
	sort(arr, arr+3);//*利用负数降序

}


int main3(){
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
	}
	//* 降序
	sort(arr, arr+3, [](int lhs, int rhs){return lhs>rhs;});	
	//*  1 2 3 4 5 6升序    lhs > rhs
	//*  6 5 4 3 2 1降序    lhs < rhs
	for(int i = 0; i < 3; ++i){
		cout << arr[i];
	}

}

//* 函数指针
int cmp(int lhs, int rhs){
    return lhs>rhs;
}
int main4(){
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
	}

	sort(arr, arr+3, cmp);	

	for(int i = 0; i < 3; ++i){
		cout << arr[i];
	}

}

//* 函数对象
class Cmp{
public:
    bool operator() (int lhs, int rhs){
        return lhs> rhs;
    }
} CMP;
int main5(){
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
	}

	sort(arr, arr+3, CMP);
    sort(arr, arr+3, Cmp());	

	for(int i = 0; i < 3; ++i){
		cout << arr[i];
	}
}
//* STL 函数对象
#include <functional>
int main5_1(){
	int arr[5]{};
	for(int i = 0; i < 3; ++i){
		cin >> arr[i];
	}

	sort(arr, arr+3, greater<int>());	
//*升序 sort(arr, arr+3, less<int>());
	for(int i = 0; i < 3; ++i){
		cout << arr[i];
	}
}

int main(){
	main5_1();
}