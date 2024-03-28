#include<stdio.h>
#include<string.h>
#include<algorithm>
char a[1000],b[1000];
char box[1000];
int main(){
    using namespace std;
    int A,B;
    int out = 0;
    scanf("%s",box);
    A = strlen(box);
    for(int i=0;i<strlen(box);i++ ){
        a[i] = box[strlen(box)-1-i]-'0';
    }
    scanf("%s",box);
    B = strlen(box);
    for(int i=0;i<strlen(box);i++ ){
        b[i] = box[strlen(box)-1-i]-'0';
    }
    for(int i = 0; i<= max(A,B);i++){
        a[i]+=b[i];
    }
    for(int i = 0; 1;i++){
        if(a[i]==0&&i >= (max(A,B) - 1)&&i>0) {
            out = i;
            break;
        }
        a[i]>9?a[i+1]+=a[i]/10,a[i]%=10:0;
    }
    for(int i = out-1; i>=0; i--){
        printf("%d",a[i]);
    }
    //printf("\n\n%d %d %d",A,B,out);
    return 0;
}