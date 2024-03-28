#include <stdio.h>
#include <algorithm>
int item[3*10000+5];
int main(){
    int w, n; scanf("%d%d", &w, &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", item+i);
    }
    std::sort(item, item+n);
    int cnt = 0;
    for(int i = 0, j = n-1; i<=j;){
        if(i!=j){
            if(item[i]+item[j]<=w){
                cnt++;
                ++i, --j;
                continue;
            }else{
                cnt++;
                --j;
                continue;
            }
        }else{
            cnt++;
            break;
        }
    }
    printf("%d", cnt);
    return 0;
}