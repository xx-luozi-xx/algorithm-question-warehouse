#include <iostream>
#define int long long
using namespace std;
const int MAX_SIZE = 1e6+30;
const int MOD = 666623333;

int prime[MAX_SIZE];
int prime_size = 0;
int isnprime[MAX_SIZE]{1,1,0};

int compute_prime(){
    for(int i = 2; i < MAX_SIZE; ++i){
        if(!isnprime[i]){
            prime[prime_size ++] = i;
        }
        for(int j = 0; i*prime[j] < MAX_SIZE and j < prime_size; ++j){
            isnprime[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
    return 0;
}   
int prime_init_ = compute_prime();

int l, r;
int vit_[MAX_SIZE];
int phi_[MAX_SIZE];
int& phi(int idx){return phi_[idx-l];}
int& vit(int idx){return vit_[idx-l];}

signed main(){
    cin >> l >> r;
    for(int i = l; i <= r; ++i){
        phi(i) = vit(i) = i;
    }
    for(int i = 0; prime[i]*prime[i] <= r; ++i){
        int p = prime[i];
        for(int j = (l+p-1)/p*p; j <= r; j+=p){
            while(vit(j)%p == 0){
                vit(j)/=p;
            }
            phi(j)=phi(j)/p*(p-1);
        }
    }
    int ans = 0;
    for(int i = l; i <= r; ++i){
        if(vit(i)>1){
            phi(i) = phi(i)/vit(i)*(vit(i)-1);
        }
        ans += i-phi(i); ans%=MOD;
    }
    cout << ans;
    return 0;
}




