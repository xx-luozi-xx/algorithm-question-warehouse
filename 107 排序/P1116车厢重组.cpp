#include <stdio.h>
int out;
void swap(int& a, int& b){
        int x = a;
        a = b , b = x;
        ++out;
}
int main(){
    int n;scanf("%d",&n);
    int*a = new int[n]{};
    for(int i = 0; i < n; scanf("%d",&a[i++]));

    for(int i = n-1; i >= 0; --i){
        for(int j = 0; j < i; ++j){
            a[j]>a[j+1]?swap(a[j],a[j+1]),0:0;
        }
    }
    printf("%d",out);
    return 0;
}