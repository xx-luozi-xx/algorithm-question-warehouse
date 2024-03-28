#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a=1;
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            a<10? printf("0%d",a++):printf("%d",a++);
        }
        printf("\n");
    }
    a=1, printf("\n");
    for(int i=0; i<n; i++){
        for(int j=n-i-1; j>0; j--){
            printf("  ");
        }
        for(int j=i+1; j>0; j--){
            a<10? printf("0%d",a++): printf("%d",a++);
        }
        printf("\n");
    }
}