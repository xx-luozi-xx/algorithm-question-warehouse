#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE (int(1e5+30))

int a[MAX_SIZE];
long long A;
int b[MAX_SIZE];
long long B;

double t[MAX_SIZE];

int n, p;

bool check(double x){
    double bad = 0;
    for(int i = 0; i < n; ++i){
        if(x*a[i]>b[i]){
            bad+=x*a[i]-b[i];
        }
    }
    return p*x>=bad;
}

int main(){
    cin >> n >> p;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", a+i, b+i);
        A+=a[i], B+=b[i];
    }
    double t_min = 0;
    double t_max = 1e10;
    if(p>=A){
        printf("-1");
        return 0;
    }
    
    double mid;
    while(t_max-t_min>=0.00001){
        mid = (t_min+t_max)/2;
        if(check(mid)){
            t_min = mid;
        }else{
            t_max = mid;
        }
    }
    printf("%lf", mid);
    return 0;
}