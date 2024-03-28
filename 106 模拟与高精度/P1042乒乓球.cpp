#include<stdio.h>
int out1[10000],out2[10000];
int ans;
int main(){
    int a1 = 0,a2 = 0,b1 = 0,b2 = 0;
    char box;
    while(scanf("%c",&box)){
        if(box == 'E'){
            printf("%d:%d\n",a1,a2);
            out1[ans]=b1,out2[ans]=b2;
            break;
        }else if(box=='W'){
            a1+=1, b1+=1;
            if(a1>=11&&a1-a2>=2){
                printf("%d:%d\n",a1,a2);
                a1=a2=0;
            }
            if(b1>=21&&b1-b2>=2){
                out1[ans]=b1,out2[ans]=b2;
                b1=b2=0;
                ans++;
            }
        }else if(box=='L'){
            a2+=1, b2+=1;
            if(a2>=11&&a2-a1>=2){
                printf("%d:%d\n",a1,a2);
                a1=a2=0;
            }
            if(b2>=21&&b2-b1>=2){
                out1[ans]=b1,out2[ans]=b2;
                b1=b2=0;
                ans++;
            }
        }
    }
    for(int i = 0;i<=ans;i++){
        printf("\n%d:%d",out1[i],out2[i]);
    }
    return 0;
}