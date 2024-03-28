#include <stdio.h>
#define I 1000
int boxing[5][5]={
    {0,I,1,1,I},
    {1,0,I,1,I},
    {I,1,0,I,1},
    {I,I,1,0,1},
    {1,1,I,I,0},
};
int a[3000],b[3000];
int A,B,n;
int out;

int main(){
    scanf("%d %d %d",&n,&A,&B);
    for(int i = 0; i<A; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i<B;i++){
        scanf("%d",&b[i]);
    }
    while(n--){
        static int ax=0,bx=0;
        out+=boxing[a[ax]][b[bx]];
        ax++,ax%=A;
        bx++,bx%=B;
    }
    return 0*printf("%d %d",out%1000,out/1000);
}