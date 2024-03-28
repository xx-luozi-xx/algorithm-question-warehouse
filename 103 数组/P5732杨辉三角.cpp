#include <stdio.h>
#define int1 unsigned long long


int1 gg(int1 a){
    int1 ans=1,aa=a;
    while(aa>0){
    ans*=aa--;
    }
    return ans;
}
int1 cc(int1 a, int1 b){
    return gg(a)/(gg(b)*gg(a-b));
}
int main(){
    int1 n;scanf("%d",&n);
    for(int1 i=0;i<=n-1;i++){
        for(int1 j=0;j<=i;j++){
            printf("%d ",cc(i,j));
        }
        printf("\n");
    }
}