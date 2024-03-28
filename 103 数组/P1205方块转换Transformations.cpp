#include <stdio.h>

int a[13][13],b[13][13],n;

void turn(int a[][13], int n);
void moni(int a[][13], int n);
bool same(int a[][13], int b[][13], int n);

int main(){
    scanf("%d",&n);
    scanf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&a[j][i]);
        }
        scanf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&b[j][i]);
        }
        i==n-1?0:scanf("\n");
    }
    turn(a,n);
    if(same(a,b,n)){
        return 0*printf("1");
    }
    turn(a,n);
    if(same(a,b,n)){
        return 0*printf("2");
    }
    turn(a,n);
    if(same(a,b,n)){
        return 0*printf("3");
    }
    turn(a,n);
    moni(a,n);
    if(same(a,b,n)){
        return 0*printf("4");
    }
    int i=3;
    while(i--){
        turn(a,n);
        if(same(a,b,n)){
            return 0*printf("5");
        }
    }
    turn(a,n),moni(a,n);
    if(same(a,b,n)){
        return 0*printf("6");
    }
    return 0*printf("7");
}


void turn(int a[][13], int n){
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[n-i-1][j]=a[j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[j][i]=b[j][i];
        }
    }
}
void moni(int a[][13], int n){
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[n-j-1][i]=a[j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[j][i]=b[j][i];
        }
    }
}
bool same(int a[][13], int b[][13], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=b[i][j]){
                return bool(0);
            }
        }
    }
    return bool(1);
}