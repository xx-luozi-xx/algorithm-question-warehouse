#include <stdio.h>

struct big{
int num[5000] = {1};
int size = 0;

void operator*=(int a);
};

int main(){
    int N;scanf("%d",&N);
    while(N--){
        int n;scanf("%d",&n);
        int A;scanf("%d",&A);
        int ans=0;
        big num;
        for(int i = 2;i<=n;i++){
            num*=i;
        }
        for(int i = 0 ;i<=num.size;i++){
            num.num[i]==A?ans++:0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

void big::operator*=(int a){
    for(int i = 0; i<=size; i++){
        num[i]*=a;
    }
    for(int i = 0; i<size;i++){
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
    for(int i = size;num[i]>=10;i++,size++){
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
}