#include <stdio.h>
char box;
int main(){
    if(scanf("%c",&box)!=EOF){
        box>='a'&&box<='z'?printf("%c",box-('a'-'A')):printf("%c",box);
        main();
    }
    return 0;   
}