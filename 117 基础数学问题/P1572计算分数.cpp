#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define int long long
using namespace std;

int read_num(){
    int sgn = 1;
    if(cin.peek() == '-'){
        sgn = -1;
        char tmp; cin >> tmp;
    }else if(cin.peek() == '+'){
        char tmp; cin >> tmp;
    }
    int ret = 0;
    while(isdigit(cin.peek())){
        char tmp; cin >> tmp;
        tmp -= '0';
        ret *= 10;
        ret += tmp;
    }
    return ret*sgn;
}

signed main(){
    cin.peek();
    int ret_a = read_num();
    char tmp; cin >> tmp;
    int ret_b = read_num();
    int gcd = __gcd(ret_a, ret_b);
    ret_a/=gcd;
    ret_b/=gcd;
    while(cin.peek()!=EOF and cin.peek()!='\n'){

    //    printf("[%d/%d]\n", ret_a, ret_b);

        int a = read_num();
        cin >> tmp;
        int b = read_num();
        gcd = __gcd(a, b);
        a/=gcd;
        b/=gcd;
        int nb = ret_b * b;
        int na = ret_a*b + a*ret_b;
        gcd = __gcd(na, nb);
        ret_a = na/gcd;
        ret_b = nb/gcd;
    }

    if(ret_a == 0){
        printf("0");
        return 0;
    }

    if((__int128)ret_a*ret_b<0){
        printf("-%lld", abs(ret_a));
        if(ret_b != 1){
            printf("/%lld", abs(ret_b));
        }
    }else{
        printf("%lld", ret_a);
        if(ret_b != 1){
            printf("/%lld", ret_b);
        }
    }
    return 0;
}