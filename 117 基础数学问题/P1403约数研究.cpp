#include <iostream>
using namespace std;
const int MAX_SIZE = 1e6+30;

bool isnprime[MAX_SIZE]{1,1,0};
int from[MAX_SIZE];

int prime[MAX_SIZE];
int prime_len = 0;

void prime_init(){
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            prime[prime_len++] = i;
            from[i] = i;
        }
        for(int j = 0; j < prime_len and i*prime[j] < MAX_SIZE; ++j){
            isnprime[i*prime[j]] = 1;
            from[i*prime[j]] = prime[j];
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}

int tag[MAX_SIZE] {};
int tags[MAX_SIZE]{};
int tags_len = 0;

int main(){
    prime_init();
    int n; cin >> n;
    unsigned long long ans = 0;
    for(int i = 1; i <= n; ++i){
        //printf("\n[i=%d]", i);
        int now = i;
        while(now != 1){
            if(tag[from[now]] == 0){
                tags[tags_len++] = from[now];
            }
            tag[from[now]] ++;
            //printf("(%d)", from[now]);
            now/=from[now];
        }
        unsigned long long a_ans = 1;
        for(int i = 0; i < tags_len; ++i){
            a_ans *= tag[tags[i]]+1;
            tag[tags[i]] = 0;
        }
        tags_len = 0;
        ans += a_ans;
    }
    cout << ans;
}

