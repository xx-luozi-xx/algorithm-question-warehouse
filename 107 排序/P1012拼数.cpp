#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    string *a = new string[n]{};
    for(int i = 0; i<n; cin>>a[i++]);
    sort(a,a+n,[](const string& lhs, const string& rhs)->bool{return lhs+rhs>rhs+lhs;});
    for(int i = 0; i<n; cout<<a[i++]);
    return 0;
}