// 浮点数
// https://www.matiji.net/exam/brushquestion/40/3181/1DC60EA6DF83A333301CFFE1407FBA59
#include <iostream>
#include <math.h>
using namespace std;
const unsigned MAX_SIZE = 1e4+30;
int n, m;
double money[MAX_SIZE];
double xxd[MAX_SIZE];
double got = 0;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> money[i];
    }
    for(int i = 0; i < m; ++i){
        int a, b;
        double num;
        cin >> a >> b >> num;
        if(money[a] < num){
            break;
        }
        money[a]-=num;
        got += num-floor(num);
        xxd[b] += num-floor(num);
        money[b] += floor(num);
        if(xxd[b] > 1){
            break;
        }
    }
    printf("%.2lf", got);
    return 0;
}