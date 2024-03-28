#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
double last = -200;

double F(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

int check(double x){
    if(F(x) < 0){return -1;}
    if(F(x) > 0){return 1;}
    if(F(x) == 0){return 0;}
}
void go_with(double lit, double big){
    if(F(lit) == 0){
        if(lit - last >0.0001){
            last = lit;
            printf("%.2lf ", lit);
        }
        return;
    }else if(F(lit) < 0){//增
        double mid;
        for(int i = 0; i < 30; ++i){
            mid = (lit+big)/2;
            if(F(mid)>0){
                big = mid;
            }else{
                lit = mid;
            }
        }
        if(mid - last > 0.0001){
            last = mid;
            printf("%.2lf ", mid);
        }
        return;
    }else{// 减
        double mid;
        for(int i = 0; i < 30; ++i){
            mid = (lit+big)/2;
            if(F(mid)>0){
                lit = mid;
            }else{
                big = mid;
            }
        }
        if(mid - last > 0.0001){
            last = mid;
            printf("%.2lf ", mid);
        }
        return;
    }
}
int main(){
    cin >> a >> b >> c >>d;
    for(double i = -100; i<100; i+=0.5){
        double _lit = i, _big = i+0.5;
        if(check(_lit)*check(_big)<=0){
            go_with(_lit, _big);
        }
    }
    return 0;
}
