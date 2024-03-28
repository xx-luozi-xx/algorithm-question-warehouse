#include <stdio.h>
#include <cmath>
bool a[1100][1100];
int x;
int main(){
    scanf("%d",&x);
    a[0][0]=1;
    for(int n = 1; n <= x; n++){
        int d = pow(2,n-1), u = pow(2,n);
        for(int i = 0; i < d; i++){
            for(int j = 0; j< d; j++){
                a[i][j+d]=a[i][j];
                a[i+d][j]=a[i][j];
            }
        }
    }
    for(int i = pow(2,x)-1;i>=0;i--){
        for(int j = pow(2,x)-1;j>=0;j--){
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    }
    return 0;
}