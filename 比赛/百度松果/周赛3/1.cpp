//斐波那契数列
// https://www.matiji.net/exam/brushquestion/45/3181/1DC60EA6DF83A333301CFFE1407FBA59
#include <iostream>
#include <string>
#define int long long
using namespace std;
int n, c;
int fib[100];
string str[2]={"IAKIOI", "WHENWILLSCORLLOFTAIWUCOMEOUT!!!"};
char xxd(int n, int c){
    if(n == 0 or n == 1) return  str[n][c-1];
    if(c > fib[n-2]) return xxd(n-1, c-fib[n-2]);
    return xxd(n-2, c); 
}

signed main(){
    fib[0] = str[0].size();
    fib[1] = str[1].size();
    for(int i = 2; i < 100; ++i){
        fib[i] = fib[i-1]+fib[i-2];
    }
    cin >> n >> c;
    cout << xxd(n, c);
    return 0;
}