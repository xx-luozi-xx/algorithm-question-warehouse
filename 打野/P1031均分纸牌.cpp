#include <stdio.h>
#define MAX_SIZE (1000)
int n;
int data[MAX_SIZE];

int main(){
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
        sum+=i[data];
    }
    sum/=n;
    int loss = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        loss += data[i]-sum;
        if(loss){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}