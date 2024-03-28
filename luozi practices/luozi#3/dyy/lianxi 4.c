#include<stdio.h>
#include<string.h>
int main(){
    char a[1000],b[1000];
    int c[1000]={0};
    scanf("%s",&a);
    scanf("%s",&b);
    int wa,wb,d;
    wa=strlen(a);
    wb=strlen(b);
    for(int i=0;i<wa;i++){
        c[i]=a[wa-1-i]-'0';
    }
    for(int i=0;i<wb;i++){
        c[i]=c[i]+b[wb-1-i]-'0';
        //* c[i]+=
    }
    for(int i=0;i<1000;i++){
        // while(c[i]>=10){
        //     c[i]=c[i]-10;
        //     c[i+1]=c[i+1]+1;
        // }
        c[i+1] += c[i]/10;
        c[i]%=10;
    }
    for(int i=999;i>=0;i--){
        if(c[i]!=0){
            d=i;
            break;
        }
    }
    for(int i=d;i>=0;i--){
        printf("%d",c[i]);
    }
    return 0;
}