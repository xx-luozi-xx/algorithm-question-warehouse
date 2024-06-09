/**
差分
https://www.matiji.net/exam/dohomework/6418/5 
*/

#include <iostream>
using namespace std;
const int MAX_SIZE = 1e5+30;
int n;
int num[MAX_SIZE];
int dif[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        dif[i] = num[i]-num[i-1];
    }
    long long neg = 0;
    long long poz = 0;
    for(int i = 2; i <= n; ++i){
        if(dif[i] > 0){
            poz += dif[i];
        }else{
            neg -= dif[i];//add
        }
    }
    cout << max(poz, neg);
    return 0;
}