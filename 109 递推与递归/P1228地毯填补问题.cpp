#include <stdio.h>
#include <math.h>
#include <stddef.h>

void full(size_t x1, size_t y1, size_t x2, size_t y2, size_t X, size_t Y){
    if(x1 == x2 && y1 == y2){
        return;
    }

    size_t x_mid = (x1+x2)/2;
    size_t y_mid = (y1+y2)/2;

    if(x1 <= X && X <= x_mid){
        if(y1 <= Y && Y <= y_mid){//*X小Y小
            printf("%d %d %d\n", x_mid+1, y_mid+1, 1);
            full(x1, y1, x_mid, y_mid, X, Y);
            full(x1, y_mid+1, x_mid, y2, x_mid, y_mid+1);
            full(x_mid+1, y1, x2, y_mid, x_mid+1, y_mid);
            full(x_mid+1, y_mid+1, x2, y2, x_mid+1, y_mid+1);
        }else{//*X小Y大
            printf("%d %d %d\n", x_mid+1, y_mid, 2);
            full(x1, y1, x_mid, y_mid, x_mid, y_mid);
            full(x1, y_mid+1, x_mid, y2, X, Y);
            full(x_mid+1, y1, x2, y_mid, x_mid+1, y_mid);
            full(x_mid+1, y_mid+1, x2, y2, x_mid+1, y_mid+1);
        }
    }else{
        if(y1 <= Y && Y <= y_mid){//*X大Y小
            printf("%d %d %d\n", x_mid, y_mid+1, 3);
            full(x1, y1, x_mid, y_mid, x_mid, y_mid);
            full(x1, y_mid+1, x_mid, y2, x_mid, y_mid+1);
            full(x_mid+1, y1, x2, y_mid, X, Y);
            full(x_mid+1, y_mid+1, x2, y2, x_mid+1, y_mid+1);
        }else{//*X大Y大
            printf("%d %d %d\n", x_mid, y_mid, 4);
            full(x1, y1, x_mid, y_mid, x_mid, y_mid);
            full(x1, y_mid+1, x_mid, y2, x_mid, y_mid+1);
            full(x_mid+1, y1, x2, y_mid, x_mid+1, y_mid);
            full(x_mid+1, y_mid+1, x2, y2, X, Y);           
        }
    }
    return;
}

int main(){
    int K, x, y;
    scanf("%d%d%d", &K, &x, &y);
    full(1, 1, pow(2,K), pow(2,K), x, y);
    return 0;
}