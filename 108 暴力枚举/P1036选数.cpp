#include <stdio.h>
#include <math.h>

long long data[30]{};
bool looked[30]{};
long long sum;
int n, k;
int cnt_of_prime;

bool is_prime(long long num){
    if(num == 2){
        return true;
    }
    const long long max = sqrt(num)+1;
    for(int i = 2; i <= max; ++i){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void bfs(int k, int last){
    if(k == 0){
        is_prime(sum)?cnt_of_prime++:0;
        return;
    }
    for(int i = last; i < n; ++i){
        if(looked[i]==false){
            looked[i] = true;
            sum+=data[i];
            bfs(k-1,i+1);
            sum-=data[i];
            looked[i] = false;
        }
    }


}

int main(){
    
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &data[i]);
    }
    
    bfs(k, 0);

    printf("%d", cnt_of_prime);


}