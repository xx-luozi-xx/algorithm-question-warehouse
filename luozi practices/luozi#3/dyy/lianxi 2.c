#include<stdio.h>
int main(){
int n;
double s=0;
scanf("%d",&n);
for(int i=1;;i++){
    s=s+1.0/i;
    if(s>n){
        printf("%d",i);
        return 0;
    }
}
return 0;
}