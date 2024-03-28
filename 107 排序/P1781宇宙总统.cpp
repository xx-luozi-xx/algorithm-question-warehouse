#include <iostream>
#include <algorithm>
using namespace std;

class amm{
public:
    int id;
    string score;

    friend ostream& operator << (ostream& out, const amm& a){
        out << a.id << endl << a.score;
        return out;
    } 
    friend istream& operator >> (istream& in, amm& a){
        static int id = 0;
        a.id = ++id;
        in>>a.score;
        return in;
    }
};

bool cmp(const amm& lhs, const amm&rhs){
    if(lhs.score.size()==rhs.score.size()){
        return lhs.score>rhs.score;
    }else{
        return lhs.score.size()>rhs.score.size();
    }
}

int main(){
    int n; cin>>n;
    amm* a = new amm[n]{};
    for(int i = 0; i< n; ++i){
        cin>>a[i];
    }
    nth_element(a,a,a+n,cmp);
    cout<<*a;
    return 0;
}