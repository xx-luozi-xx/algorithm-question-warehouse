#include <stdio.h>
#include <algorithm>
struct Milk{
    int money;
    int amount;
}milk[5000+5];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &milk[i].money, &milk[i].amount);
    }
    std::sort(milk, milk+m, [](const Milk&lhs, const Milk&rhs){
        return lhs.money < rhs.money;
    });
    unsigned long long spend = 0;
    int get = 0;
    for(int i = 0; i<m; ++i){
        if(get < n){
            if(get+milk[i].amount <= n){
                get+=milk[i].amount;
                spend+=milk[i].amount*milk[i].money;
            }else{
                spend+=(n-get)*milk[i].money;
                get = n;
            }
        }else{
            break;
        }
    }
    printf("%llu", spend);
    return 0;
}