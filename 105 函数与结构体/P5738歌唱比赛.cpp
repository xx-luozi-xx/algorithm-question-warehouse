#include <stdio.h>
#include <algorithm>
using namespace std;
double out;
char a[30];
int m,n;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        for(int i = 0; i<m;i++){
            scanf("%hd",&a[i]);
        }
        sort(a,a+m);
        double avr = 0;
        for(int i = 1; i <m-1;i++ ){
            avr += a[i];
        }
        avr/=(m-2)*1.0;
        out > avr?0:out = avr;
    }
    return 0*printf("%.2f",out);
}