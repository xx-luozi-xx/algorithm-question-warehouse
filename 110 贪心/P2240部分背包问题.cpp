#include <stdio.h>
#include <algorithm>

struct dui{
    int v;
    int w;
};

dui a[100+5];

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; ++i){
        int w_, v_;
        scanf("%d %d", &w_, &v_);
        a[i].w = w_;
        a[i].v = v_; 
    }
    std::sort(a, a+n, [](const dui& lhs, const dui& rhs){
        return (lhs.v*1.0/lhs.w)>(rhs.v*1.0/rhs.w);
    });
    int get_w = 0;
    double get_v = 0;
    for(int i = 0; i < n; ++i){
        if(get_w + a[i].w <= t){
            get_w += a[i].w;
            get_v += a[i].v;
        }else{
            get_v += (t - get_w)*(a[i].v*1.0/a[i].w);
            get_w = t;
            break;
        }
    }
    printf("%.2lf", get_v);
    return 0;
}