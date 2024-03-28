#include <stdio.h>
#define max(a, b) ((a)<(b)?(b):(a))
#define MAX_SIZE (10000+30)


int hight[MAX_SIZE];

int ans_x[MAX_SIZE];
int ans_y[MAX_SIZE];
int ans_len = 0;

int main(){
    int l, h, r;
    while(scanf("%d", &l) != EOF){
        if(l == -1){
            break;
        }
        scanf("%d%d", &h, &r);
        for(int i = l; i < r; ++i){
            hight[i] = max(hight[i], h);
        }
    }

    int now_h = 0;
    for(int i = 0; i < MAX_SIZE; ++i){
        if(now_h != hight[i]){
            ans_x[ans_len] = i;
            ans_y[ans_len] = now_h;
            ans_len++;
            ans_x[ans_len] = i;
            ans_y[ans_len] = hight[i];
            ans_len++;
        }
        now_h = hight[i];
    }
    int is_x = 1;
    for(int i = 0; i < ans_len; ++i){
        printf("%d ", is_x?ans_x[i]:ans_y[i]);
        is_x = !is_x;
    }
    return 0;
}