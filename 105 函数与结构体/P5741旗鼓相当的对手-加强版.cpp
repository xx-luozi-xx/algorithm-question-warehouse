#include <stdio.h>
#include <cmath>
struct stu{
    int a,b,c;
    char name[20];
    void get(){
        scanf("%s %d %d %d",name,&a,&b,&c);
    }
    int print(bool a){
        return printf("%s",name),a?printf(" "):printf("\n");
    }
    bool operator |(const stu& g){
        return abs(a-g.a)<=5&&abs(b-g.b)<=5&&abs(c-g.c)<=5&&abs(a+b+c-g.a-g.b-g.c)<=10;
    }
};

int main(){
    int n;scanf("%d",&n);
    stu a[n];
    for(int i = 0;i<n;i++){
        a[i].get();
    }
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            a[i]|a[j]?a[i].print(1),a[j].print(0):0;
        }
    }
    return 0;
}