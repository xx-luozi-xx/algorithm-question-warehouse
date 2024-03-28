#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    unsigned n,B;cin>>n>>B;
    unsigned *a = new unsigned[n]{};
    for(int i = 0; i < n; cin>>a[i++]);
    sort(a,a+n,[](unsigned lhs, unsigned rhs) -> bool {return lhs>rhs;});
    unsigned box = 0, cnt = 0;
    for(int i = 0; box < B; ++i){
        box+=a[i];
        cnt++;
    }
    cout<<cnt;
    return 0;
}