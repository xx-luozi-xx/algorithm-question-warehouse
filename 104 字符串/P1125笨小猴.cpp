#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
char a[233];
int main(){
    scanf("%s",&a);
    int ans=1,max=0,min=100;
    int n=strlen(a);
    std::sort(a,a+n);
    //printf("%s",a);
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            ans++;
        }else{
            ans>max?max=ans:0;
            ans<min?min=ans:0;
            ans=1;
        }
    }
    ans>max?max=ans:0;
    ans<min?min=ans:0;
    //printf("\n%d %d",max,min);
    n=max-min;
    for(int i=2;i<=sqrt(n)||n<2;i++){
        if(!(n%i)||n<2){
            return 0*printf("No Answer\n0");
        }
    }
    return 0*printf("Lucky Word\n%d",n);
}