#include <stdio.h>
#include <math.h>

int s[20]{};
int b[20]{};
int add[20]{1};

int min(int a, int b){
    return a<b?a:b;
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i<n; ++i){
        scanf("%d %d", s+i, b+i);
    }

    int sb_min = __INT_MAX__;
    while(add[n]==0){
        int S = 1;
        int B = 0;
        for(int i = 0; i < n; ++i){
            if(add[i] == 1){
                S *= s[i], B += b[i];
            }
        }
        sb_min = min(sb_min, abs(S-B));

        //TODO
        add[0]++;
        for(int i = 0; i < n; ++i){
            if(add[i] == 2){//* add[i] > 1
                add[i+1]++; //* add[i+1] = add[i]/2;
                add[i] = 0; //* add[i] %=2 ;
            }else{
                break;
            }
        }
    }
    printf("%d", sb_min);
    return 0;
}

