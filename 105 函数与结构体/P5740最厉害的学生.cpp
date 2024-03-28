#include <stdio.h>
struct stu{
    int a,b,c;
    char name[20];
    stu(int x):a(0),b(0),c(-1){};
    stu(){
        scanf("%s %d %d %d",name,&a,&b,&c);
    }
    bool operator >(const stu& x){
        return a+b+c>x.a+x.b+x.c;
    }
    int print(){
        return printf("%s %d %d %d",name,a,b,c);
    }
};
int main(){
    stu out(0);
   // stu box(0);
    int n;scanf("%d",&n);
    while(n--){
        stu box;
        box>out?out = box:0;
    }
    return 0*out.print();
}