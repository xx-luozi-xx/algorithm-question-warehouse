#include <iostream>
#include <algorithm>

using namespace std;
class amm{
private:
    int _id = 0;
    int _score = 0;
public:
    int id() const {return _id;}
    int score() const {return _score;}
    friend istream& operator >> (istream& in, amm& x){
        in>>x._id>>x._score;
        return in;
    }
    friend ostream& operator << (ostream& out, const amm& x){
        out<<x._id<<" "<<x._score<<endl;
        return out;
    }
};
bool cmp(const amm& lhs, const amm& rhs){
    if(lhs.score()!=rhs.score()){
        return lhs.score()>rhs.score();
    }else{
        return lhs.id()<rhs.id();
    }
}
int main(){
    int n,m;cin>>n>>m;
    m=m*1.5;
    amm *a = new amm[n]{};
    for(int i = 0; i<n; cin>>a[i++]);
    sort(a,a+n,cmp);

    int cnt = 0;
    for(int i = 0; a[i].score() >= a[m-1].score(); ++i) ++cnt;
    
    cout<< a[m-1].score() << " " << cnt << endl;
    for(int i = 0; i < cnt; cout<< a[i++]);
    return 0;
}