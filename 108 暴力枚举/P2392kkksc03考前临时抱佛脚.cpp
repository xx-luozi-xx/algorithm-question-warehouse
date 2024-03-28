#define BEG10

#ifdef BEG10
#include <stdio.h>
inline int min(int a, int b){
    return a<b?a:b;
}
inline int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int task[23]{};
    int task_size[4]{};
    int all = 0;
    for(int i = 0; i < 4; ++i){
        scanf("%d",task_size+i);
    }
    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < task_size[j]; ++i){
            scanf("%d",task+i);
        }
        int choose[23]{};
        int min_time = __INT_MAX__;
        while(choose[task_size[j]]==0){
            int brain1 = 0, brain2 = 0;
            for(int i = 0; i < task_size[j]; ++i){
                choose[i]?brain1+=task[i]:brain2+=task[i];
            }
            min_time = min(min_time, max(brain1, brain2));

            //TODO 进位
            choose[0]++;
            for(int i = 0; i < task_size[j]; ++i){
                if(choose[i] == 2){
                    ++choose[i+1];
                    choose[i] = 0;
                }else{
                    break;
                }
            }
        }
        all += min_time;
    }
    printf("%d", all);
    return 0;
}
#endif

#ifdef TAN_XIN
#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> task;
    int all = 0;

    int cnt[4];
    for(int i = 0; i < 4; ++i){
        scanf("%d",cnt+i);
    }

    for(int s = 0; s < 4; ++s){
        for(int i = 0; i < cnt[s]; ++i){
            int input; scanf("%d",&input);
            task.push(input);
        }
        int brain1 = 0, brain2 = 0;
        while(!task.empty()){
            brain1<brain2?brain1+=task.top():brain2+=task.top();
            task.pop();
        }
        all+=brain1>brain2?brain1:brain2;
    }
    printf("%d", all);
}
#endif