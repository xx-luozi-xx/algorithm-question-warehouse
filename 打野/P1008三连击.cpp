#include <stdio.h>

int used[20] = {};

int bag[10] = {};
int bag_len = 0;

void check(){
    int a = bag[0]*100 + bag[1]*10 + bag[2];
    int b = bag[3]*100 + bag[4]*10 + bag[5];
    int c = bag[6]*100 + bag[7]*10 + bag[8];

    if(a*2 == b && a*3 == c){
        printf("%d %d %d\n", a, b, c);
    }
}

void get_a_num(){
    if(bag_len == 9){
        check();
        return;
    }

    for(int i = 1; i < 10; ++i){
        if(!used[i]){
            used[i] = 1;
            bag[bag_len++] = i;
            get_a_num();
            bag_len--;
            used[i] = 0;
        }
    }
}

int main(){
    get_a_num();
    return 0;
}