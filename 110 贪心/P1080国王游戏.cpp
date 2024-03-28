#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 5000

class Big{
    public:
    int data[MAX_SIZE]={};
    bool operator < (const Big& rhs){
        for(int i = MAX_SIZE -1; i>=0; --i){
            if(rhs.data[i]!=data[i]){
                return data[i] < rhs.data[i];
            }
        }
        return 0;//equal
    }
    Big& operator *= (int n){
        for(int i = 0; i < MAX_SIZE; ++i){
            data[i]*=n;
        }
        for(int i = 1; i < MAX_SIZE; ++i){
            data[i] += data[i-1]/10;
            data[i-1]%=10;
        }
        return *this;
    }
    Big operator /(int n){
        int div[MAX_SIZE]{};
        int div_size = 0;
        while(n){
            div[div_size++] = n%10;
            n/=10;
        }

        Big rec;
        Big tmp = *this;

        for(int i = MAX_SIZE-2; i >= div_size-1; --i){
            while(1){//sub
                bool ok = 1;
                for(int j = div_size-1, ii = i; j >= 0; --j, --ii){
                    if(tmp.data[ii] != div[j]){
                        ok = tmp.data[ii] > div[j];
                        break;
                    }
                }//equal is ok
                if(tmp.data[i+1]){
                    ok = 1;
                }

                if(ok){
                    rec.data[i-(div_size-1)]++;
                    //被除数减一份
                    for(int j = 0, ii = i-div_size+1; j < div_size; ++j, ++ii){
                        tmp.data[ii]-=div[j];
                    }
                    //向上处理借位
                    for(int ii = i-div_size+1; ii <= i;  ++ii){//从刚刚减的最低位开始，到high_use
                        if(tmp.data[ii] < 0){
                            tmp.data[ii]+=10;
                            tmp.data[ii+1]--;
                        }
                    }
                }else{
                    break;
                }
            }
        }
        return rec;
    }
    void print(){
        bool first = 0;
        for(int i = MAX_SIZE-1; i > 0; --i){
            if(first||data[i]){
                first = 1;
                printf("%d", data[i]);
            }
        }
        printf("%d", data[0]);
    }
};
int main(){
    int n; scanf("%d", &n);
    auto *data = new pair<int, int>[n+1]{};
    for(int i = 0; i <= n; ++i){
        scanf("%d %d", &data[i].first, &data[i].second);
    }
    sort(data+1, data+n+1, [](const pair<int, int>& lhs, const pair<int ,int>& rhs){
        return lhs.first*lhs.second < rhs.first*rhs.second;
    });

    Big MQ; MQ.data[0] = 1;
    Big max_val;
    for(int i = 1; i <= n; ++i){
        MQ *= data[i-1].first;
        Big tmp = MQ/data[i].second;
        if(max_val < tmp){
            max_val = tmp;
        }
    }
    max_val.print();

    return 0;

}