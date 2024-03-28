/*
题目描述

有一只小鱼，它平日每天游泳 250250 公里，周末休息（实行双休日)，假设从周 xx 开始算起，过了 nn 天以后，小鱼一共累计游泳了多少公里呢？
输入格式

输入两个正整数 x,nx,n，表示从周 xx 算起，经过 nn 天。
输出格式

输出一个整数，表示小鱼累计游泳了多少公里。
输入输出样例
输入 #1

3 10

输出 #1

2000
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x, n, s = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        if ((x != 6) && (x != 7))
            s += 250;
        
        
        if (x == 7)//* 整数循环群进位 x++, x%=7;
            x = 1;
        else
            x++;
    }
    cout << s;
    return 0;
}
// O(1)
int main1(){
    //* 如果超过7天，这七天总花费 5*250;
    int n, x;
    int s = (n/7)*5*250;
    n%=7;

    for (int i = 0; i < n; i++)
    {
        if ((x != 6) && (x != 7))
            s += 250;
        
        
        if (x == 7)//* 整数循环群进位 x++, x%=7;
            x = 1;
        else
            x++;
    }
    cout << s;
}