#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> box;
    int n;
    scanf("%d", &n);
    while(n--){
        int input;
        scanf("%d", &input);
        box.push(input);
    }
    unsigned long long val = 0;
    while(box.size()!=1){
        int a = box.top(); box.pop();
        int b = box.top(); box.pop();
        val += a+b;
        box.push(a+b);
    }
    printf("%llu", val);
    return 0;   
}