#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[3];
    char b[5];
    for(int i=0;i<3;i++)scanf("%d",&a[i]);
    scanf("\n%s",b);
    sort(a,a+3);
    for(int i=0;i<3;i++){
        b[i]=='A'?printf("%d ",a[0]):0;
        b[i]=='B'?printf("%d ",a[1]):0;
        b[i]=='C'?printf("%d ",a[2]):0;        
    }
}