#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    int x=__gcd(a[0],a[2]);
    a[0]/=x,a[2]/=x;
    printf("%d/%d",a[0],a[2]);
}

/*

int gcd(int x,int y)
{
    int r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;//最大公约数，就是题目所说的约分---
    }
    return y;//返回值

}
 */