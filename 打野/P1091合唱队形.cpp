#include <stdio.h>

int hight[105]{};
int R[105]{};
int L[105]{};

inline int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", hight+i);
        R[i] = L[i] = 1;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(hight[j]<hight[i]){
                L[i] = max(L[i], L[j]+1);
            }
        }
    }
    for(int i = n-1; i >= 0; --i){
        for(int j = n-1; j > i; --j){
            if(hight[j]<hight[i]){
                R[i] = max(R[i], R[j]+1);
            }
        }
    }
    int max_in = 0x80000000;
    for(int i = 0; i < n; ++i){
        max_in = max(max_in, L[i]+R[i]-1);
    }
    printf("%d", n-max_in);
    return 0;
}