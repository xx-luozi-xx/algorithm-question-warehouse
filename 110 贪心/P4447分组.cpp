#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int data[100000+5];
int num[100000+5];
int cnt[100000+5];
int num_size = 0;

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    sort(data, data+n);
    num[0] = data[0];
    cnt[0] = 1;
    num_size = 1;
    for(int i = 1; i < n; ++i){
        if(data[i] == num[num_size-1]){
            cnt[num_size-1]++;
        }else{
            num[num_size++] = data[i];
            cnt[num_size-1] = 1;
        }
    }
    
    int min_size = __INT_MAX__;
    priority_queue<int, vector<int>, greater<int>> now, next;
    for(int i = 0; i < cnt[0]; ++i){
        next.push(1);
    }
    int last_num = num[0];

    for(int i = 1; i < num_size; ++i){
        now = next;
        priority_queue<int, vector<int>, greater<int>> tmp;
        next.swap(tmp);
        if(num[i] == last_num+1){
            if(cnt[i] >= now.size()){
                int MAX_I = cnt[i]-now.size();
                for(int i = 0; i < MAX_I; ++i){//*多出来的自成一组
                    next.push(1);
                }
                while(!now.empty()){//*能接上的接上
                    next.push(now.top()+1);
                    now.pop();
                }
            }else{
                for(int i = 0; i < cnt[i]; ++i){//*能接上的接上
                    next.push(now.top()+1);
                    now.pop();
                }
                while(!now.empty()){//*多出来的没法继续了
                    min_size = min(min_size, now.top());
                    now.pop();
                }
            }
        }else{//*没法接上
            while(!now.empty()){//*弹出原来所有
                min_size = min(min_size, now.top());
                now.pop();
            }
            //*加入现在所有
            for(int i = 0; i < cnt[i]; ++i){
                next.push(1);
            }
        }
        last_num = num[i];
    }
    //todo 剩下的弹出
    while(!next.empty()){
        min_size = min(min_size, next.top());
        next.pop();
    }
    printf("%d", min_size);
    return 0;
}