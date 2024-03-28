#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class point{
public:
    int data[3] = {};

    friend istream& operator >> (istream& in, point &x){
        in>>x.data[0]>>x.data[1]>>x.data[2];
        return in;
    }
};
bool cmp(const point& lhs, const point& rhs){
    return lhs.data[2]<rhs.data[2];
}

double dis(const point& lhs, const point& rhs){
    double box = 0;
    for(int i = 0; i<3; ++i){
        box+=(lhs.data[i]-rhs.data[i])*(lhs.data[i]-rhs.data[i]);
    }
    return sqrt(box);
}
int main(){
    int n;cin>>n;
    point *a = new point[n]{};
    for(int i = 0; i < n; cin>>a[i++]);
    sort(a,a+n,cmp);
    double out = 0;
    for(int i = 0; i<n-1; ++i){
        out+=dis(a[i],a[i+1]);
    }
    printf("%.3lf",out);
    return 0;
}