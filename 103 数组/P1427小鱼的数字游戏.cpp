/*
#include <stack>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    stack<int>a;
    int box;
    while(scanf("%d",&box),box){
        a.push(box);
    }
    while(!a.empty()){
        printf("%d ",a.top()),a.pop();
    }
    return 0;
}
*/

#include <stdio.h>
int main(){
    int a[200]={0}, i;
    for(i=0;scanf("%d",&a[i]),a[i];i++);
    for(i--;i>=0;printf("%d ",a[i--]));
    return 0;
}