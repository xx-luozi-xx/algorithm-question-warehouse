#include <iostream>
#include <algorithm>
using namespace std;

class student{
private:
    int _id = 0;
    int _chinese = 0;
    int _math = 0;
    int _english = 0;
    int _sum = 0;
public:
    friend istream& operator >> (istream& in, student& stu){
        static int id = 1;
        stu._id = id++;
        in >> stu._chinese >> stu._math >> stu._english;
        stu._sum = stu._chinese + stu._math + stu._english;
        return in;
    }
    friend ostream& operator << (ostream& out, const student& stu){
        out << stu._id << " " << stu._sum <<endl; 
        return out;
    }
    friend bool x(const student& lhs, const student& rhs){
        if(lhs._sum==rhs._sum){
            if(lhs._chinese==rhs._chinese){
                return lhs._id<rhs._id;
            }else{
                return lhs._chinese>rhs._chinese;
            }
        }else{
            return lhs._sum>rhs._sum;
        }
    }
};

bool x(const student& lhs, const student& rhs);

int main(){
    int n; cin>>n;
    student *a = new student[n]{};
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a,a+n,x);
    for(int i = 0; i<5; ++i){
        cout<< a[i];
    }
    return 0;
}

