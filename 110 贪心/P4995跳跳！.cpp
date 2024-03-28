#include<stdio.h>
#include<algorithm>
#define MAX_SIZE 305
int data[MAX_SIZE]{};
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", data+i);
    }
    std::sort(data, data+n);
    unsigned long long out = 0;
    bool upper = true;
    int last = 0;
    for(int i = 0, j = n-1, cnt = 0; cnt < n; ++cnt){
        if(upper){
            out += (data[j]-last)*(data[j]-last);
            last = data[j--];
        }else{
            out += (last-data[i])*(last-data[i]);
            last = data[i++];
        }
        upper=!upper;
    }
    printf("%llu", out);
    return 0;
}