#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 20
int n;
double x[MAX_SIZE];
double y[MAX_SIZE];

bool vit[MAX_SIZE];

int choose[MAX_SIZE];
int choose_size;
double len[MAX_SIZE];
int len_size;

double min_ = __INT_MAX__;

void dfs(int times){
    if(times == 0){
        min_ = min(len[len_size-1], min_);
    }

    for(int i = 1; i <= n; ++i){
        if(!vit[i]){
            choose[choose_size++] = i;
            vit[i] = 1;
            len[len_size] = len[len_size-1]+
                            sqrt((x[choose[choose_size-1]]-x[choose[choose_size-2]])*
                                (x[choose[choose_size-1]]-x[choose[choose_size-2]])+
                                (y[choose[choose_size-1]]-y[choose[choose_size-2]])*
                                (y[choose[choose_size-1]]-y[choose[choose_size-2]]));
            len[len_size++] <= min_ ?dfs(times-1),0:NULL;
            
            vit[i] = 0;
            choose_size--;
            len_size--;
        }
    }    

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lf %lf", x+i, y+i);
    }
    
    choose[choose_size++] = 0;
    len[len_size++] = 0;

    dfs(n);

    printf("%.2lf", min_);
    return 0;

}