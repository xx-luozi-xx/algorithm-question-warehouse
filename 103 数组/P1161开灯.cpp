#include <stdio.h>
bool x[2000000+233];
double a;
int n,t;
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%lf %d",&a,&t);
        for(int i=1;i<=t;i++){
            x[int(i*a)]=!x[int(i*a)];
        }
    }
    for(int i=1;i<=2000000+233;i++){
        if(x[i]) return 0*printf("%d",i);
    }
}