#include<stdio.h>
int main(){
    char name[233];
    int age,score;
    int n;scanf("%d",&n);
    while(n--){
        scanf("%s %d %d",name,&age,&score);
        printf("%s %d %d\n",name,age+1,int(score*1.2>600?600:score*1.2));
    }
    return 0;
}