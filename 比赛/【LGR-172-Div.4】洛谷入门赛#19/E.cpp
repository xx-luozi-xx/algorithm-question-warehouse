#include <iostream>
using namespace std;
const int MAX_SIZE = 1e6+30;

int n;
int chair[MAX_SIZE];
int to_chair[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> chair[i];
        to_chair[chair[i]] = i;
    }
    for(int i = 1; i <= n-1; ++i){
        int now = to_chair[i];
        int air = to_chair[0];
        swap(chair[now], chair[air]);
        swap(to_chair[i], to_chair[0]);
    }
    for(int i = 1; i <= n; ++i){
        cout << chair[i] << ' ';
    }
    return 0;
}