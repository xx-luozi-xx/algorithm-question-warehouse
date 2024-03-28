#include <stdio.h>
#include <stdlib.h>
int main(){
    char box[100]={0};
    int a,b,mode;
    int n;
    scanf("%d\n",&n);
    while(n--){
        scanf("%s",box);
        box[0]>='a'?mode=box[0],scanf("%d",&a):a=atoi(box);
        scanf("%d",&b);
        if(mode == 'a'){
            printf("\n%d\n",printf("%d+%d=%d",a,b,a+b));
        }else if(mode == 'b'){
            printf("\n%d\n",printf("%d-%d=%d",a,b,a-b));
        }else if(mode == 'c'){
            printf("\n%d\n",printf("%d*%d=%d",a,b,a*b));
        }
    }
    return 0;
}