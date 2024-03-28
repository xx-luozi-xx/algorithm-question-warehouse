#include <stdio.h>

#define M 25
#define N 25
#define X 20*20*20

struct Itme
{
    int position[M]={0};
    int time[M]={0};
    int stage = 0;
    int ltime = -1;
    
    int po(){
        return position[stage];
    } 
    int t(){
        return time[stage];
    }
};
struct Machine
{
    static int allTime;
    bool stage[X]={0};
};

int Machine::allTime = 0;

Itme itme[N];
Machine machine[M];
int go[M*N];
int n,m;

int main(){
    scanf("%d %d",&m,&n);
    for(int i = 0; i<n*m;++i){
        scanf("%d",&go[i]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d",&itme[i].position[j]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d",&itme[i].time[j]);
        }
    }

    for(int i = 0; i<n*m; ++i){
        Itme &aitme = itme[go[i]-1];
        Machine &amachine = machine[aitme.po()];

        for(int i = aitme.ltime;1;0){
            int j;
            int Y = 1;
            for(j = i+1;j-i<=aitme.t();j++){
                if(amachine.stage[j]){
                    Y=0;
                    break;
                }
            }
            if(Y){//满足 
                for(int j = i + 1;j - i <=aitme.t();j++){
                    amachine.stage[j] = 1;
                }
                aitme.ltime = i + aitme.t();
                aitme.stage++;
                aitme.ltime > Machine::allTime?Machine::allTime=aitme.ltime:0;
                break;
            }else{//不满足
                i = j;
            }
        }
    }
    return 0*printf("%d",Machine::allTime+1);
}