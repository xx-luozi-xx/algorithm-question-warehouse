#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class amm{
public:
    string name;
    int val = 0;

    bool operator < (const amm& x){
        return val<x.val;
    }
    friend istream& operator >> (istream& in, amm& x){
        static int id = 99;
        in >> x.name;
        int y,m,d;
        in>>y>>m>>d;
        x.val=y*1000000+m*10000+d*100+(id--);
        return in;
    }
    friend ostream& operator << (ostream& out, const amm& x){
        out<<x.name<<endl;
        return out;
    }
};
int main(){
    int n; cin>>n;
    amm* a = new amm[n]{};
    for(int i = 0; i<n; cin>>a[i++]);
    sort(a,a+n);
    for(int i = 0; i<n; cout<<a[i++]);
    return 0;
}