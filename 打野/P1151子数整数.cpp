#include <bits/stdc++.h>
#define sync ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int k;

bool check(int i){
    int a = i/100;
    int b = (i%10000)/10;
    int c = i%1000;

    return !(a%k||b%k||c%k);

}

int main(){
    sync;
    cin >> k;
    bool yes = 0;
    for(int i = 10000; i <= 30000; ++i){
        if(check(i)){
            yes = 1;
            cout << i << endl;
        }
    }
    yes?0:printf("No");
    return 0;
}