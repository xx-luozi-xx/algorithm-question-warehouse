#include <stdio.h>
int a[20+20+40+3],s1,s2,s3,big,out;
int main(){
    scanf("%d %d %d",&s1,&s2,&s3);
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                a[i+j+k]++;
            }
        }
    }
    for(int i=1;i<=s1+s2+s3;i++){
        big<a[i]?big=a[i],out=i:0;
    }
    return 0*printf("%d",out);
}