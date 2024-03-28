#include <stdio.h>
#include <algorithm>
struct People{
    int id;
    int time;
};

People people[1000+5];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int input;
        scanf("%d", &input);
        people[i].id = i+1;
        people[i].time = input;
    }
    std::sort(people, people+n, [](const People& lhs, const People& rhs){
        if(lhs.time!=rhs.time){
            return lhs.time<rhs.time;
        }else{
            return lhs.id<rhs.id;
        }
    });
    unsigned long long all_time = 0;
    for(int i = 0; i < n; ++i){
        all_time += people[i].time*(n-1-i);//*接水的人不算等待
        printf("%d ", people[i].id);
    }
    printf("\n%.2lf",all_time*1.0/n);
    return 0;
}