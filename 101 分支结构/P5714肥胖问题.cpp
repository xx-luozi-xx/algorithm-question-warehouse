#include <iostream>
using namespace std;
int main(){
    double m,h;
    cin>>m>>h;
    m = m/h/h;
    if(m<18.5)printf("Underweight");
    else if(m<24)printf("Normal");
    else{
        cout<<m<<endl;
        printf("Overweight");
    }
}