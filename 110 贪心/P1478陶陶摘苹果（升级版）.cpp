#include <stdio.h>
#include <algorithm>
using namespace std;

struct Apple{
    int h;
    int s;
}apple[5000+5];

int main(){
    int n, s; scanf("%d %d", &n, &s);
    int h1, h2; scanf("%d %d", &h1, &h2);
    int h = h1 + h2;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &apple[i].h, &apple[i].s);
    }

    std::sort(apple, apple+n, [](const Apple& lhs, const Apple& rhs){
        return lhs.s < rhs.s;
    });

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(apple[i].h <= h){
            if(apple[i].s <= s){
                cnt++;
                s -= apple[i].s;
            }else{
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}