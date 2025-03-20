#include <bits/stdc++.h>
using namespace std;
int find_max(int a, int n, int* M){
    printf("? %d ", n);
    for(int i = a; i <=n; ++i){
        printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    int max;
    scanf("%d", &max);
    *M = max;
    while(1){
        if(a == n){
            return a;
        }
        int mid = (a+n)/2;
        printf("? %d ", mid - a + 1);
        for(int i = a; i <= mid; ++i){
            printf("%d ", i);
        }
        printf("\n");
        fflush(stdout);
        int next_max;
        scanf("%d", &next_max);
        if(next_max == max){
            n = mid;
        }else{
            a = mid + 1;
        }
    }
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n, k; scanf("%d %d", &n, &k);
        set<int> sets[k];
        for(int i = 0; i < k; ++i){
            int c; scanf("%d", &c);
            for(int j = 0; j < c; ++j){
                int input; scanf("%d", &input);
                sets[i].emplace(input);
            }
        }
        //找最大值所在的编号
        int M;
        int M_i = find_max(1, n, &M);
        int key[k]{};
        for(int i = 0; i < k; ++i){
            if(sets[i].count(M_i)){
                printf("? %d ", n-sets[i].size());
                for(int j = 1; j <= n; ++j){
                    if(!sets[i].count(j)){
                        printf("%d ", j);
                    }
                }
                printf("\n");
                fflush(stdout);
                scanf("%d", &key[i]);
            }else{
                key[i] = M;
            }
        }
        printf("! ");
        for(int i = 0; i < k; ++i){
            printf("%d ",key[i]);
        }
        printf("\n");
        fflush(stdout);
        scanf("%s", key);
    }
    return 0;
}