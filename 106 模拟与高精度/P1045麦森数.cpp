#include <stdio.h>
#include <cmath>

int num[1000] = {2};//底数
int out[1000] = {1};//奇数指数积

void arrmut(int*a, const int *b);//高精*=

int main(){
    int p;scanf("%d",&p);
    printf("%d\n",int(p*log10(2)+1));
//快速幂
    while(p-1){
        if(p&1){
            arrmut(out, num);
            p--;
        }else{
            arrmut(num, num);
            p/=2;
        }
    }
    arrmut(num, out);
//-1
    for(int i = 0; i<500;++i ){
        if(num[i]-1>=0){
            num[i]-=1;
            break;
        }else{
            num[i] = 9;
        }
    }
//print
    for(int i = 499; i>=0; --i){
        printf("%d",num[i]);
        i%50==0?printf("\n"):0;
    }
    return 0;
}

void arrmut(int*a, const int *b){
    int box[1000] = {0};//int *box = new int[1000]{};
    for(int i = 0; i<500; i++){
        for(int j = 0; j<500; j++){
            box[i+j]+=a[i]*b[j]; 
        }
        for(int k = 0; k<500; k++){
            box[k+1]+=box[k]/10;
            box[k]%=10;
        }
    }
    for(int i = 0; i<1000; i++){
        a[i] = box[i];
    }
    //delete box[];
}