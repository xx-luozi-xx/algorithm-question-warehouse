#include <stdio.h>
inline bool ifgreatyear(int a){
    return !(a%4)&&(a%100)||!(a%400);
}
int out[3000];
int ans;
int main(){
    int x,y;scanf("%d %d",&x,&y);
    for(int i = x;i<=y;i++){
        ifgreatyear(i)?out[ans++]=i:0;
    }
    printf("%d\n",ans);
    for(int i = 0;i<ans;i++){
        printf("%d ",out[i]);
    }
    return 0;
}