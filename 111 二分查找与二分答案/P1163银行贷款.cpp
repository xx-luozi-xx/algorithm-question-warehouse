#include <bits/stdc++.h>
using namespace std;

int n,m,k;

bool check_(double x){
    double sum = n;
    for(int i = 1; i <=k; ++i){
        sum= sum*(1+x)-m;
    }
    return sum<0;
}

int main(){
    cin >> n >> m >>k;
    double ans = 0;
    double _min = 0, _max = 10;
    while(_max-_min>0.0001){
        double mid = (_min+_max)/2.0;
        ans = mid;
        if(check_(mid)){
            _min = mid;
        }else{
            _max = mid;
        }
    }
    printf("%.1lf", _min*100);
    return 0;
}