#include <stdio.h>
#include <cmath>
bool ifprime(int a){
    if(a<2){
        return 0;
    }
    for(int i = 2;i<=sqrt(a);i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n; scanf("%d",&n);
    while(n--){
        int box;
        scanf("%d",&box);
        ifprime(box)?printf("%d ",box):0;
    }
return 0;
}