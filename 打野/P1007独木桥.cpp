#include <iostream>
using namespace std;

int main(){
    int L, N;
    cin >> L >> N;
    int max_time = 0;
    int min_time = 0;
    for(int i = 0; i < N; ++i){
        int pos; cin >> pos;    
        max_time = max(max_time, max(pos, L+1-pos));
        min_time = max(min_time, min(pos, L+1-pos));
    }
    cout << min_time << ' ' << max_time;
    return 0;
}