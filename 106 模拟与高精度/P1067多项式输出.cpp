#include <stdio.h>
int main(){
    int n;scanf("%d",&n);
    for(int i = n;i>=0;i--){
        int box;scanf("%d",&box);
        i==n?0:(box>0?printf("+"):0);
        box?(box==1&&i!=0?0:(box==-1&&i!=0?printf("-"):(printf("%d",box)))):0;
        box&&i!=0?printf("x"),(i>1?printf("^%d",i):0):0;
    }
    return 0;
}