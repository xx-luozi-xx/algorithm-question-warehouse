#include <cstdio>
int Local(int a){
    return a*5;
}
int Luogu(int a){
    return a*3+11;
}
int main(){
    int a;
    scanf("%d",&a);
    Local(a)<Luogu(a)?printf("Local"):printf("Luogu");
}