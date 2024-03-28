#include <cstdio>
int pro1(int a){
    return !(a&1);
}
int pro2(int a){
    return a>4 && a<=12;
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d %d %d %d",pro1(a)&&pro2(a),pro1(a)||pro2(a),pro1(a)+pro2(a)==1,pro1(a)+pro2(a)==0);
}