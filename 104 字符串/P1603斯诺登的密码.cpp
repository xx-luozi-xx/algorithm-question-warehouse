#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
inline int gg(int a){
    return (a*a)%100;
}
int getint(const char* a)
{
    if(!strcmp(a,"one")){
        return gg(1);   
    }else if(!strcmp(a,"two")){
        return gg(2);   
    }else if(!strcmp(a,"three")){
        return gg(3);
    }else if(!strcmp(a,"four")){
        return gg(4);
    }else if(!strcmp(a,"five")){
        return gg(5);
    }else if(!strcmp(a,"six")){
        return gg(6);
    }else if(!strcmp(a,"seven")){
        return gg(7);
    }else if(!strcmp(a,"eight")){
        return gg(8);
    }else if(!strcmp(a,"nine")){
        return gg(9);
    }else if(!strcmp(a,"ten")){
        return gg(10);
    }else if(!strcmp(a,"eleven")){
        return gg(11);
    }else if(!strcmp(a,"twelve")){
        return gg(12);
    }else if(!strcmp(a,"thirteen")){
        return gg(13);
    }else if(!strcmp(a,"fourteen")){
        return gg(14);
    }else if(!strcmp(a,"fifteen")){
        return gg(15);
    }else if(!strcmp(a,"sixteen")){
        return gg(16);
    }else if(!strcmp(a,"seventeen")){
        return gg(17);
    }else if(!strcmp(a,"eighteen")){
        return gg(18);
    }else if(!strcmp(a,"nineteen")){
        return gg(19);
    }else if(!strcmp(a,"twenty")){
        return gg(20);
    }else if(!strcmp(a,"a")){
        return gg(1);
    }else if(!strcmp(a,"both")){
        return gg(2);
    }else if(!strcmp(a,"another")){
        return gg(1);
    }else if(!strcmp(a,"first")){
        return gg(1);
    }else if(!strcmp(a,"second")){
        return gg(2);
    }else if(!strcmp(a,"third")){
        return gg(3);
    }else{
        return 0;
    }
}
void out(int a){
    static int first=0;
    static int ans=0;
    ans++;
    if(first==0){
        if(a==0){
            ans==6?printf("0"):0;
            return;
        }else{
            printf("%d",a);
            first = 1;
        }
    }else{
        a<10?printf("0"):0;
        printf("%d",a);
    }
}
int main(){
    int a[6]={0};
    for(int i=0;i<6;i++){
        char box[233];
        scanf("%s",box);
        if(i==5){
            box[strlen(box)]=='.'?box[strlen(box)]=0:0;
        }
        a[i]=getint(box);
    }
    sort(a,a+6);
    for(int i = 0;i<6;i++){
        out(a[i]);
        //printf("%d ",a[i]);
    }
    return 0;
}