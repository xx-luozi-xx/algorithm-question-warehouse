#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct people{
    char name[50];
    int rank;
    int xp;
    int lvl;
    int time;

    people() = default;
    void get();
    void print();
};

int Rank(const char*a);
const char* Rank(int a);

bool sorter(const people&a, const people&b);
bool so_xp(const people&a,const people&b);

void give(people& a);
people ren[150];


int main(){
    int n;scanf("%d",&n);
    for(int i = 0; i< n;++i){
        ren[i].get();
        i<3?ren[i].print(),0:0;
    }
    sort(ren+3,ren+n,so_xp);
    for(int i = 3;i<n;i++){
        give(ren[i]);
    }
    sort(ren+3,ren+n,sorter);
    for(int i = 3;i<n;i++){
        ren[i].print();
    }
    return 0;
}
void give(people& a){
    static int ans=0;
    ans++;//2 4 7 25

    if(ans<=2){
        a.rank=2;return;
    }
    if(ans<=2+4){
        a.rank=3;return;
    }
    if(ans<=2+4+7){
        a.rank=4;return;
    }
    if(ans<=2+4+7+25){
        a.rank=5;return;
    }
    a.rank=6;return;
}
void people::print(){
    printf("%s %s %d\n",name,Rank(rank),lvl);
}
void people::get(){
        static int t = 0;
        t++,time = t;
        scanf("%s",name);
        char box[50];
        scanf("%s",box);
        rank = Rank(box);
        scanf("%d %d",&xp,&lvl);
}
int Rank(const char*a){
    if(!strcmp(a,"BangZhong"))return 6;
    if(!strcmp(a,"JingYing"))return 5;
    if(!strcmp(a,"TangZhu"))return 4;
    if(!strcmp(a,"ZhangLao"))return 3;
    if(!strcmp(a,"HuFa"))return 2;
    if(!strcmp(a,"FuBangZhu"))return 1;
    if(!strcmp(a,"BangZhu"))return 0;
}
const char* Rank(int a){
    switch (a){
        case 0: return "BangZhu";
        case 1: return "FuBangZhu";
        case 2: return "HuFa";
        case 3: return "ZhangLao";
        case 4: return "TangZhu";
        case 5: return "JingYing";
        case 6: return "BangZhong";
    }
}
bool sorter(const people&a, const people&b){
    return a.rank<b.rank||(a.rank==b.rank&&(a.lvl>b.lvl||a.lvl==b.lvl&&a.time<b.time));
}
bool so_xp(const people&a,const people&b){
    return a.xp>b.xp||a.xp==b.xp&&a.time<b.time;
}

