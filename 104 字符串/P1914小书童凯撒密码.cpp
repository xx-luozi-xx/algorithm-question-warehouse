#include <stdio.h>
char a;
int n;
int main(){
    scanf("%d\n",&n);
    while(scanf("%c",&a)+1){
        printf("%c",(a-'a'+n)%26+'a');
    }
    return 0;
}