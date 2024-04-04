// https://www.matiji.net/exam/brushquestion/25/3181/1DC60EA6DF83A333301CFFE1407FBA59

//计时器骗分大法
//正解是可达性搜索

#include <iostream>
using namespace std;

int main(){
    int a, n; cin >> a >> n;
    a %= n;
    for(int i = 0; i < 1e7; ++i){
        if(a == 0){
            cout << "Yes"; 
            return 0;
        }
        a <<= 1; a %= n;
    }
    cout << "No";
}
