#include <stdio.h>
int main(){
    int out, now = 0, mom = 0;
    for(int i=1;i<=12;i++){
        now+=300,scanf("%d",&out);
        if(out > now){
            return 0*printf("-%d",i);
        }else{
            mom += (now-=out)/100*100,now%=100;
        }
    }
    return 0*printf("%d",int(1.2*mom)+now);
}