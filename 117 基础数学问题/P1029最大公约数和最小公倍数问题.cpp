#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5+30;

int prime[MAX_SIZE], prime_size = 0;
bool isnprime[MAX_SIZE] = {1, 1, 0};

int get_prime()noexcept{
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            prime[prime_size++] = i;
        }
        for(int j = 0; j < prime_size && i*prime[j] < MAX_SIZE; ++j){
            isnprime[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
    return 0;
}
int get_prime_do = get_prime();


int main(){
    int a, b; cin >> a >> b;
    if(b%a != 0){
        cout << 0;
        return 0;
    }
    b/=a;
    unsigned long long ans = 1;
    for(int i = 0; b!=1; ++i){
        if(b%prime[i] == 0){
            ans <<= 1;
            while(b%prime[i] == 0){
                b/=prime[i];
            }
        }
    }
    cout << ans;
    return 0;
}