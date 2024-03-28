#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAX_SIZE = 1e5+30;

bool isnprime[MAX_SIZE]{1,1,0};
int prime[MAX_SIZE];
int prime_len = 0;
void prime_init(){
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            prime[prime_len++] = i;
        }
        for(int j = 0; j < prime_len and i*prime[j] < MAX_SIZE; ++j){
            isnprime[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}

int n;
int m1, m2;
int S[MAX_SIZE];

int main(){
    prime_init();
    cin >> n;
    cin >> m1 >> m2;
    for(int i = 0; i < n; ++i){
        cin >> S[i];
    }

    unordered_map<int, int> cntM;
    int prime_i = 0;
    while(m1 > 1 and prime_i < prime_len){
        if(m1%prime[prime_i] == 0){
            cntM[prime[prime_i]]++;
            m1/=prime[prime_i];
        }else{
            prime_i++;
        }
    }
    if(m1 > 1){
        cntM[m1]++;
    }

    for(auto itr = cntM.begin(); itr!= cntM.end(); ++itr){
        itr->second*=m2;
    }

    int ans = 0x3f3f3f3f;
    for(int i = 0; i < n; ++i){
        unordered_map<int, int>cntS;
        prime_i = 0;
        while(S[i] > 1 and prime_i < prime_len){
            if(S[i] % prime[prime_i] == 0){
                cntS[prime[prime_i]]++;
                S[i]/=prime[prime_i];
            }else{
                prime_i++;
            }
        }
        if(S[i] > 1){
            cntS[S[i]]++;
        }
        int ans__ = 0;
        for(auto itr = cntM.begin(); itr != cntM.end(); ++itr){
            if(itr->second){
                int k = itr->first;
                if(cntS[k] == 0){
                    goto next_i;
                }
                ans__ = max(ans__, (cntM[k]+cntS[k]-1)/cntS[k]);
            }
        }
        //printf("[%d]\n", ans__);
        ans = min(ans, ans__);
        next_i:
        int next_i;
    }
    if(ans == 0x3f3f3f3f){
        printf("-1");
    }else{
        printf("%d", ans);
    }
    return 0;
}