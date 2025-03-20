#include <stdio.h>
int data[100000+30];

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    if(n&1){
        printf("YES\n");
        printf("%d\n", n-1);
        for(int i = 1; i < n; ++i){
            if(i&1){
                printf("%d ", i);
            }else{
                printf("%d %d\n", i, n);
            }
        }
        for(int i = 1; i < n; ++i){
            if(i&1){
                printf("%d ", i);
            }else{
                printf("%d %d\n", i, n);
            }
        }
    }else{
        int s = 0;
        for(int i = 0; i < n; ++i){
            s^=data[i];
        }
        if(s){
            printf("NO\n");
        }else{
            printf("YES\n");
            printf("%d\n", n-2);
            for(int i = 1; i < n-1; ++i){
                if(i&1){
                    printf("%d ", i);
                }else{
                    printf("%d %d\n", i, n-1);
                }
            }            
            for(int i = 1; i < n-1; ++i){
                if(i&1){
                    printf("%d ", i);
                }else{
                    printf("%d %d\n", i, n-1);
                }
            }
        }
    }
    return 0;
}