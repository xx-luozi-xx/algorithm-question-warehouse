#include <stdio.h>

struct bigInt{
    int num[5000] = {0};
    int size = 0;

    bigInt() = default;
    bigInt(int a);
    
    void operator*=(int a);
    void print();
};

int split[(int)1e5+233];
int ans;

int main(){
    int a;scanf("%d",&a);
    if(a == 3){
        return 0*printf("1 2\n2");
    }else if(a == 4){
        return 0*printf("1 3\n3");
    }

    for(int i = 2;a-i>=0;i++){
        split[ans++] = i;
        a-=i;
    }
    split[--ans] += a;

    bigInt out = 1;
    for(int i = 0; i<=ans; i++){
        printf("%d ",split[i]);
        out *= split[i];
    }
    printf("\n");
    out.print();
    return 0;
}

bigInt::bigInt(int a):size(0){
    num[0] = a;
    for(;num[size]>=10;size++){
        num[size+1] = num[size]/10;
        num[size]%=10;
    }
}
void bigInt::operator*=(int a){
    for(int i = 0; i <= size; i++){
        num[i]*=a;
    }
    for(int i = 0; i< size; i++){
        num[i+1] += num[i]/10;
        num[i]%=10;
    }
    for(int i = size; num[i]>=10;i++,size++){
        num[i+1] = num[i]/10;
        num[i]%=10;
    }
}
void bigInt::print(){
    for(int i = size; i>=0; i--){
        printf("%d",num[i]);
    }
}