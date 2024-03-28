#include <stdio.h>
#include <algorithm>

struct Time{
    int start;
    int end;
}time[1000000+5];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int s, e;
        scanf("%d %d", &s, &e);
        time[i].start = s;
        time[i].end = e;
    }
    std::sort(time, time+n, [](const Time& lhs, const Time& rhs){
        return lhs.end<rhs.end;
    });
    int now_time = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(time[i].start >= now_time){
            cnt++;
            now_time = time[i].end;
        }
    }
    printf("%d", cnt);
    return 0;
}
