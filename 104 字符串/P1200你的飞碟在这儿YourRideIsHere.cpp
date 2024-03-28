#include<stdio.h>
int getint(const char*a){
    int ans=1;
    for(int i=0;a[i]!=0;i++){
        ans*=(a[i]-'A'+1);
        ans%=47;
    }
    return ans;
}

int main(){
    char a[10],b[10];
    scanf("%s\n%s",a,b);
    getint(a)==getint(b)?printf("GO"):printf("STAY");
    return 0;
}