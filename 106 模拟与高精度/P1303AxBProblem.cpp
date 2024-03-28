#include <stdio.h>
#include <algorithm>
#include <string.h>

int a[5000],b[5000];
int out[5000];
char box[5000];
int A,B,OUT;

int main(){
    scanf("%s",box);
    A=strlen(box);
    for(int i = 0; i<A; i++){
        a[i] = box[A-1-i]-'0';
    }
    scanf("%s",box);
    B=strlen(box);
    for(int i = 0; i<B;i++){
        b[i] = box[B-1-i]-'0';
    }
    for(int i = 0; i<B;i++){
        for(int j = 0; j<A;j++){
            out[i+j]+=b[i]*a[j];
        }
        for(int i = 0; i<5000;i++){
            out[i]>9?out[i+1]+=out[i]/10,out[i]%=10:0;
        }
    }
    for(int i = 5000-1;i>=0;i--){
        if(out[i]){
            OUT = i;
            break;
        }
    }
    for(int i = OUT; i>=0; i--){
        printf("%d",out[i]);
    }
    //printf("%d %d",A,B);
    return 0;
}