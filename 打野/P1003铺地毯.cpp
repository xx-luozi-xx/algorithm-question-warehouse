#include <stdio.h>
#define MAX_SIZE (10000+30)

int n;
int a[MAX_SIZE];
int b[MAX_SIZE];
int g[MAX_SIZE];
int k[MAX_SIZE];
int x,y;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d %d", a+i, b+i, g+i, k+i);
    }
    scanf("%d %d", &x, &y);
    int ans = -2;
    for(int i = 0; i < n; ++i){
        if(a[i]<=x and x <= a[i]+g[i] and b[i]<=y and y<= b[i]+k[i]){
            ans = i;
        }
    }
    printf("%d", ans+1);
}