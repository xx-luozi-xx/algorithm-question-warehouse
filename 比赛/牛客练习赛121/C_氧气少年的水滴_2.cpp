#include <iostream>
using namespace std;
const int MAX_SIZE = 2e5+30;

int n, p;
int num[MAX_SIZE];

int main(){
    int T; cin >> T;
    while(T--){
        cin >> n >> p;
        for(int i = 1; i <= n; ++i){
            cin >> num[i];
        }
        int l_bag = 0, r_bag = 0;
        int l = p, r = p+1;
        l_bag = 1;
        while((l >= 1 and l_bag) or (r <= n and r_bag)){
            while(l >= 1 and l_bag){
                int need = 10-num[l];
                if(l_bag >= need){
                    num[l]+=need; l_bag-=need;
                }else{
                    num[l]+=l_bag; l_bag = 0;
                }
                if(num[l] == 10){
                    l--;
                    l_bag ++;
                    r_bag ++;
                }
            }
            while(r <= n and r_bag){
                int need = 10-num[r];
                if(r_bag >= need){
                    num[r]+=need; r_bag-=need;
                }else{
                    num[r]+=r_bag; r_bag = 0;
                }
                if(num[r] == 10){
                    r++;
                    l_bag ++;
                    r_bag ++;
                }
            }
        }
        cout << l_bag << ' ' << r_bag << '\n';
    }
    return 0;
}