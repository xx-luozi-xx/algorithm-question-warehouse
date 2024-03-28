#include <cstdio>
int main(){
    double a,all=0;
    scanf("%lf",&a);
    a>400?all+=(a-400)*0.5663,a=400:0;
    a>150?all+=(a-150)*0.4663,a=150:0;
    all+=a*0.4463;
    printf("%.1lf",all);
}