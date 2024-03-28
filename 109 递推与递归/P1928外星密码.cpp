#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[20000+5];
int decode(int index, int times);
int main(){

    scanf("%s", str);
    str[strlen(str)] = ']';
    
    decode(0, 1);

    return 0;
}
int decode(int index, int times){
    int i;
    while(times--){
        for(i = index; str[i]!=']'; ++i){
            if(str[i]=='['){
                ++i;
                int n = str[i]-'0';
                ++i;
                isdigit(str[i])?n*=10, n+=str[i]-'0', ++i:0;
                i = decode(i, n);//* 跳至decode完后的右括号
            }else{
                putchar(str[i]);
            }
        }
    }
    return i;
}
