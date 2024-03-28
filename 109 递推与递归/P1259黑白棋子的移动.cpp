#include <stdio.h>
#include <algorithm>
using std::swap;

#define MAX_SIZE (100*2+10)
char str[MAX_SIZE];

void move(int n);

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        str[i] = 'o';
    }
    for(int i = n; i < 2*n; ++i){
        str[i] = '*';
    }
    str[2*n] = str[2*n+1] = '-';
    str[2*n+2] = '\0';
    printf("%s\n", str);

    move(n);
    return 0;
}

void move(int n){
    if(n == 4){
        //todo 打表 好好好
        swap(str[3],str[8]);
        swap(str[4],str[9]);
        printf("%s\n", str);

        swap(str[3],str[7]);
        swap(str[4],str[8]);
        printf("%s\n", str);

        swap(str[1],str[7]);
        swap(str[2],str[8]);
        printf("%s\n", str);

        swap(str[1],str[6]);
        swap(str[2],str[7]);
        printf("%s\n", str);
        
        swap(str[0],str[6]);
        swap(str[1],str[7]);
        printf("%s\n", str);    
        return;   
    }
    swap(str[n-1], str[2*n]);
    swap(str[n], str[2*n+1]);
    printf("%s\n", str);

    swap(str[n-1], str[2*n-2]);
    swap(str[n], str[2*n-1]);
    printf("%s\n", str);

    move(n-1);
}