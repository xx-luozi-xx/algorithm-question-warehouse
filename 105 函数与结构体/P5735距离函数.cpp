#include <stdio.h>
#include <cmath>
struct point
{
    double x,y;
    point(){
        scanf("%lf%lf",&x,&y);
    }
    double operator |(const point& p)const{
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }
};
int main(){
    point p1;
    point p2;
    point p3;
    printf("%.2f",(p1|p2)+(p1|p3)+(p2|p3));
}