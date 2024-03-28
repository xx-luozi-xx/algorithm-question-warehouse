#include <cstdio>
int main(){
    int n,min=8848,box;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&box);
        box<min?min=box:0;
    }
    printf("%d",min);
}