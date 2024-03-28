#include <stdio.h>
#define MOD ((int)1e9+7)
#define MAX_SIZE ((int)5e3+5)
using namespace std;
#define FINISHED

int cnt[2*MAX_SIZE]{};
unsigned long long out = 0;

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int input; scanf("%d", &input);
        cnt[input]++;
    }
#ifdef FINISHED
    for(int ib = 1; ib < MAX_SIZE; ++ib){
        for(int ic = ib; ic < MAX_SIZE; ++ic){
            int a = ib+ic;
            if(cnt[a]>1){
                unsigned long long mut_a = (cnt[a])*(cnt[a]-1)/2;
                unsigned long long mut_b;
                if(ib==ic){
                    mut_b = cnt[ib]*(cnt[ib]-1)/2;
                }else{
                    mut_b = cnt[ib]*cnt[ic];
                }      
                out += ((mut_a%MOD)*(mut_b%MOD))%MOD;
                out%=MOD; 
            }
        }
    }
#endif
#ifdef OUD2
    for(int i = 0; i < MAX_SIZE; ++i){
        if(cnt[i] > 1){
            unsigned long long mut_a = (cnt[i])*(cnt[i]-1)/2;
            for(int ib = 1; ib < i; ++ib){
                for(int ic = ib; ic <i; ++ic){
                    if(ib+ic==i&&cnt[ib]*cnt[ic]!=0){
                        unsigned long long mut_b;
                        if(ib==ic){
                            mut_b = cnt[ib]*(cnt[ib]-1)/2;
                        }else{
                            mut_b = cnt[ib]*cnt[ic];
                        }
                        out += ((mut_a%MOD)*(mut_b%MOD))%MOD;
                        out%=MOD; 
                    }
                }
            }
        }
    }
#endif
#ifdef OUD
    for(int i = 0; i < MAX_SIZE; ++i){
        if(icnt[i]!=0){
            data[data_size] = i;
            cnt[data_size] = icnt[i];
            ++data_size;
        }
    }
    for(int i = 0; i < data_size; ++i){
        if(cnt[i]>1){//选两条这个边
            int A = data[i];
            unsigned long long mut_a = (cnt[i])*(cnt[i]-1)/2;
            for(int ib = 0; ib < data_size; ++ib){
                for(int ic = ib; ic < data_size; ++ic){
                    if(data[ib] + data[ic] == A){
                        unsigned long long mut_b;
                        if(ib!=ic){
                            mut_b = cnt[ib] * cnt[ic];
                        }else{
                            mut_b = (cnt[ib])*(cnt[ib]-1)/2;
                        }
                        out += ((mut_a%MOD)*(mut_b%MOD))%MOD;
                        out%=MOD; 
                    }
                }
            }
        }
    }
#endif
    printf("%d", out);
    return 0;
}