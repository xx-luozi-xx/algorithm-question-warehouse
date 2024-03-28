#include <stdio.h>

int main(){
    unsigned in; scanf("%u", &in);
    unsigned hi = in >> 16;
    unsigned lo = in << 16;
    printf("%u", hi | lo);
    return 0;
}