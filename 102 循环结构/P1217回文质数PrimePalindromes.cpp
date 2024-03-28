#include <cstdio>
#include <cmath>
int back(int a){//查找第一个回文数
    int n = log10(a);
    int f = 1;
    for(int aa=a;1;aa++){
        f = 1;
        for(int i=0,j=n;i<n;i++,j--){
            if((aa/(int)pow(10,j))%10!=(aa/(int)pow(10,i))%10) f = 0;
        }
        if(f){return aa;}
    }
}
int next(int a){//生成下一个回文数
    int n = log10(a)+1;
    if(!(n%2)){//偶数位
        int haf = a/(int)pow(10,n/2);
        if((int)log10(haf)==(int)log10(haf+1)){
            haf++;
            int last=0;
                for(int i=(int)log10(haf),j=0;i>=0;i--,j++){
                    last += ((haf/(int)pow(10,j))%10)*pow(10,i);
                }
            return int(haf*pow(10,(int)log10(haf)+1)+last);
        }else{  
            return (int)pow(10,n)+1;
        }
    }else{//奇数位
        int haf = a/(int)pow(10,n/2);
        if((int)log10(haf)==(int)log10(haf+1)){
            haf++;
            int rehaf = haf/10, last=0;
                for(int i=(int)log10(rehaf),j=0;i>=0;i--,j++){
                    last += ((rehaf/(int)pow(10,j))%10)*pow(10,i);
                }
            return last + int(haf*pow(10,(int)log10(haf)));
        }else{  
            return (int)pow(10,n)+1;
        }
    }
}
int prime(int a){//质数判断
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){return 0;}
    }return 1;
}
int main(){
    int a,b;scanf("%d %d",&a,&b);
    for(int i=back(a);i<=b;i=next(i)){
        prime(i)?printf("%d\n",i):0;
    }return 0;
}