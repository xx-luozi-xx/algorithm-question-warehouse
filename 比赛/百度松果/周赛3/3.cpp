#include <iostream>
#include <map>
using namespace std;
const int MAX_SIZE  = 1e5+30;
int n;
int num_a[MAX_SIZE];
int num_b[MAX_SIZE];

int xxd(int* a, int *b){
    map<int, int> sta, stb;
    for(int i = 0; i < n; ++i){
        sta[a[i]]++;
        stb[b[i]]++;
    }
    int ret = 0;
    for(auto itr = sta.rbegin(); itr != sta.rend(); ++itr){
        while(itr->second != 0){
            int now = itr->first;
            auto itrb = stb.lower_bound(now);
            if(itrb == stb.begin()){//没有比他小的
                if(itrb->first == now){//平局
                    ret ++;
                    itrb->second--;
                    if(itrb->second == 0){
                        stb.erase(itrb);
                    }
                }else{//必输
                    void();
                }
            }else{//有比它小的
                itrb --;
                ret+=2;
                itrb->second--;
                if(itrb->second == 0){
                    stb.erase(itrb);
                }
            }
            itr->second --;
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num_a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> num_b[i];
    }
    cout << xxd(num_a, num_b) << ' ' << 2*n-xxd(num_b, num_a);
    return 0;
}
