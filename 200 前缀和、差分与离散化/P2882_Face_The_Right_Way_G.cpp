#include <iostream>
using namespace std;
const int MAX_SIZE = 1e4+30;

int n;
int num[MAX_SIZE];
int sub[MAX_SIZE];

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        char input; cin >> input;
        num[i] = (input == 'F');
    }
    int M = 0x3f3f3f3f;
    int K;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            sub[j] = num[j]-num[j-1];
        }
        int now = 0;
        int yes = 1;
        int the_m = 0;
        for(int j = 1; j <= n; ++j){
            now += sub[j]; now%=2;
            if(now == 0){
                if(j+i-1 > n){//out of range
                    yes = 0; break;
                }else{
                    sub[j]++; now ++;
                    sub[j+i]--;
                    the_m ++;
                }
            }
        }
        if(yes){
            if(the_m < M){
                M = the_m;
                K = i;
            }
        }
    }
    cout << K << ' ' << M;
    return 0;
}