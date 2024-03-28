#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int abs_ = 100000000;
    int x_, y_;
    for(int i = 0; i < 3; ++i){
        int x = a[i];
        int y = a[0]+a[1]+a[2]-a[i];
        if(x < y){
            swap(x, y);
        }
        if(x - y < abs_){
            abs_ = x-y;
            x_ = x;
            y_ = y;
        }
    }
    cout << x_ << ' ' << y_;
    return 0;
}